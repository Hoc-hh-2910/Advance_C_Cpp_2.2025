# Tên chương trình
TARGET = Json

# Thư mục chứa file header và source code
HEADER_DIR = Header
SOURCE_DIR = Source

# Các tệp nguồn và tệp object tuong ứng
SOURCES = $(wildcard $(SOURCE_DIR)/*.c)
OBJECTS = $(SOURCES:.c=.o)

# Trình biên dịch và các cờ
CC = gcc
CFLAGS = -I$(HEADER_DIR) -Wall -Wextra

# Quy tắc đầu tiên là quy tắc mặc định sẽ được thực thi
all: $(TARGET)

# Quy tắc để tạo ra tệp thực thi
$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

# Quy tắc để biên dịch các tệp .c thành các tệp .o
$(SOURCE_DIR)/%.o: $(SOURCE_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Quy tắc để làm sạc thư mục build
clean:
	rm -f $(SOURCE_DIR)/*.o $(TARGET)
run: $(TARGET)
	./$(TARGET)
# Quy tắc giả (phony target) để chạy chương trình
.PHONY: all clean