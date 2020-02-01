
CC=gcc
TARGET_DIR=target
OBJ_DIR=$(TARGET_DIR)/obj
DEP_DIR=$(TARGET_DIR)/dep
TARGET=$(TARGET_DIR)/a.out

SRC_DIR=.
INC_FLAGS=-I./include
LINK_FALGS:=
CC_FLAGS:=$(INC_FLAGS) $(LINK_FALGS) -W -Wall

DIRS=:$(shell find $(SRC_DIR) -maxdepth 3 -type d)
VPATH=$(DIRS)

SOURCES:=$(foreach dir, $(DIRS), $(wildcard $(dir)/*.c))
OBJS:=$(addprefix $(OBJ_DIR)/, $(patsubst %.c, %.o, $(notdir $(SOURCES))))
DEPS:=$(addprefix $(DEP_DIR)/, $(patsubst %.c, %.d, $(notdir $(SOURCES))))

ifeq ($(DBG), 1)
	CC_FLAGS+=-g -D DEBUG
endif

ifeq ($(RUN), 1)
	EXEC=@echo "Running..." && ./$(TARGET)
endif

all:$(TARGET)
	@echo "Done"
	$(EXEC)

$(TARGET):$(OBJS)
	@if [ ! -d $(TARGET_DIR) ]; then mkdir -p $(TARGET_DIR); fi;
	@echo $(OBJS)
	$(CC) $^ $(LINK_FALGS) -o $@

$(OBJ_DIR)/%.o:%.c
	@if [ ! -d $(OBJ_DIR) ]; then mkdir -p $(OBJ_DIR); fi;
	$(CC) -c $(CC_FLAGS) $< -o $@

$(DEP_DIR)/%.d:%.c
	@if [ ! -d $(DEP_DIR) ]; then mkdir -p $(DEP_DIR); fi;\
	set -e; rm -f $@;
	$(CC) -MM $(CC_FLAGS) $< > $@;
	@sed 's,\($*\)\.o[ :]*,$(OBJ_DIR)/\1.o $@ : ,g' < $@ > $@;\
	rm -f $@

-include $(DEPS)
.PHONY:clean
clean:
	-rm -rf $(TARGET_DIR)
