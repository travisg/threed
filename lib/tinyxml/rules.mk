# included from the main client build
LOCAL_DIR := $(GET_LOCAL_DIR)

OBJS += \
	$(LOCAL_DIR)/tinyxml.o \
	$(LOCAL_DIR)/tinyxmlparser.o \
	$(LOCAL_DIR)/tinyxmlerror.o \
	$(LOCAL_DIR)/tinystr.o

CFLAGS += -I$(LOCAL_DIR)/..

