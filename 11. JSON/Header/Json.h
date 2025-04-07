#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <stdbool.h>


typedef enum {
    JSON_NULL,
    JSON_BOOLEAN,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} JsonType;

typedef struct JsonValue {
    JsonType type;
    union {
        int boolean;
        double number;
        char *string;
        struct {
            struct JsonValue *values;
            size_t count;
        } array;
        struct {
            char **keys;
            struct JsonValue *values;
            size_t count;
        } object;
    } value;
} JsonValue;

/**
 * @brief   Phân tích cú pháp chuỗi JSON.
 * @param   json   Con trỏ đến chuỗi JSON đầu vào.
 * @return  JsonValue*   Trả về con trỏ đến phần tử mới được thêm vào.
 */
JsonValue *parse_json(const char **json);

/**
 * @brief   Giải phóng bộ nhớ cho giá trị JSON.
 * @param   json_value   Con trỏ đến giá trị JSON cần giải phóng.
 * @return  void
 */
void free_json_value(JsonValue *json_value);

/**
 * @brief   Phân tích cú pháp một giá trị JSON với giá trị là NULL.
 * @param   json   Con trỏ đến chuỗi JSON đầu vào.
 * @return  JsonValue*   Trả về con trỏ đến giá trị JSON đã phân tích cú pháp.
 */
JsonValue *parse_null(const char **json);

/**
 * @brief   Phân tích cú pháp một giá trị JSON với giá trị là boolean.
 * @param   json   Con trỏ đến chuỗi JSON đầu vào.
 * @return  JsonValue*   Trả về con trỏ đến giá trị JSON đã phân tích cú pháp.
 */
JsonValue *parse_boolean(const char **json);

/**
 * @brief   Phân tích cú pháp một giá trị JSON với giá trị là số.
 * @param   json   Con trỏ đến chuỗi JSON đầu vào.
 * @return  JsonValue*   Trả về con trỏ đến giá trị JSON đã phân tích cú pháp.
 */
JsonValue *parse_number(const char **json);

/**
 * @brief   Phân tích cú pháp một giá trị JSON với giá trị là chuỗi.
 * @param   json   Con trỏ đến chuỗi JSON đầu vào.
 * @return  JsonValue*   Trả về con trỏ đến giá trị JSON đã phân tích cú pháp.
 */
JsonValue *parse_string(const char **json);

/**
 * @brief   Phân tích cú pháp một giá trị JSON với giá trị là mảng.
 * @param   json   Con trỏ đến chuỗi JSON đầu vào.
 * @return  JsonValue*   Trả về con trỏ đến giá trị JSON đã phân tích cú pháp.
 */
JsonValue *parse_array(const char **json);

/**
 * @brief   Phân tích cú pháp một giá trị JSON với giá trị là đối tượng.
 * @param   json   Con trỏ đến chuỗi JSON đầu vào.
 * @return  JsonValue*   Trả về con trỏ đến giá trị JSON đã phân tích cú pháp.
 */
JsonValue *parse_object(const char **json);

/**
 * @brief   Bỏ qua các ký tự trắng trong chuỗi JSON.
 * @param   json   Con trỏ đến chuỗi JSON đầu vào.
 * @return  void
 */
static void skip_whitespace(const char **json);

/**
 * @brief   Hiển thị giá trị JSON.
 * @param   json_value   Con trỏ đến giá trị JSON cần hiển thị.
 * @return  void
 */
void test(JsonValue* json_value);