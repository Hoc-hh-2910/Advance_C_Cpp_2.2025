# JSON

**Khái niệm:**
JSON là viết tắt của "JavaScript Object Notation" (Ghi chú về Đối tượng JavaScript). Đây là một định dạng truyền tải dữ liệu phổ biến trong lập trình và giao tiếp giữa các máy chủ và trình duyệt web, cũng như giữa các hệ thống khác nhau.

JSON được thiết kế để dễ đọc và dễ viết cho con người, cũng như dễ dàng để phân tích và tạo ra cho máy tính. Nó sử dụng một cú pháp dựa trên cặp key - value, tương tự như các đối tượng và mảng trong JavaScript. Mỗi đối tượng JSON bao gồm một tập hợp các cặp "key" và "value", trong khi mỗi mảng JSON là một tập hợp các giá trị.

**Ví dụ:**

```C
object
“{ 
  "name": "John Doe",
  "age": 30.0,
  "city": "New York",
  "isStudent": false,
  "grades": [85, 90, 78]
}”
```

# Phân tích code JSON:

Ta có một chuỗi JSON được cấp vào được định nghĩa trong biến ``json_str``

```C
const char* json_str = ...
```

Phân tích chuỗi JSON thông qua hàm ``parse_json`` và lưu kết quả vào biến ``json_value``

```C
JsonValue* json_value = parse_json(&json_str);
```

Trong hàm ``parse_json`` trước tiên sẽ loại bỏ các khoảng trắc (nếu có)

```C
while (isspace(**json)) {
  (*json)++;
}
```

Tiếp đó ta phân tích các ký tự trong chuỗi thông qua hàm ``switch-case``

```C
    switch (**json) {
        case 'n':
            return parse_null(json);
        case 't':
        case 'f':
            return parse_boolean(json);
        case '\"':
            return parse_string(json);
        case '[':
            return parse_array(json);
        case '{':
            return parse_object(json);
        default:
            if (isdigit(**json) || **json == '-') {
                return parse_number(json);
            } else {
                // Lỗi phân tích cú pháp
                return NULL;
            }
    }
```

Khi gặp ký tự ``'n'`` trong chuỗi ``json``, chương trình nhảy vào function ``parse_null``:

```C
JsonValue *parse_null(const char **json) {
    // Bỏ qua các ký tự trắng trong chuỗi JSON
    skip_whitespace(json);

    // Kiểm tra xem chuỗi có phải là "null" hay không
    // Nếu đúng, tạo một giá trị JSON với kiểu JSON_NULL
    // và trả về con trỏ đến giá trị đó
    // Nếu không, trả về NULL
    if (strncmp(*json, "null", 4) == 0) {
        JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
        value->type = JSON_NULL;
        *json += 4;
        return value;
    }
    return NULL;
}
```

Khi gặp ký tự ``'t'`` và ``'f'``, chương trình nhảy vào function ``parse_boolean``:

```C
JsonValue *parse_boolean(const char **json) {
    // Bỏ qua các ký tự trắng trong chuỗi JSON
    skip_whitespace(json);

    // Kiểm tra xem chuỗi có phải là "true" hoặc "false" hay không
    // Nếu đúng, tạo một giá trị JSON với kiểu JSON_BOOLEAN
    // và giá trị tương ứng (true hoặc false)
    // Nếu không, trả về NULL
    JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
    if (strncmp(*json, "true", 4) == 0) {
        value->type = JSON_BOOLEAN;
        value->value.boolean = true;
        *json += 4;
    } else if (strncmp(*json, "false", 5) == 0) {
        value->type = JSON_BOOLEAN;
        value->value.boolean = false;
        *json += 5;
    } else {
        free(value);
        return NULL;
    }
    return value;
}
```

Khi gặp ký tự ``'\'``, chương trình nhảy vào function ``parse_string``:

```C
JsonValue *parse_string(const char **json) {
    // Bỏ qua các ký tự trắng trong chuỗi JSON
    skip_whitespace(json);

    // Kiểm tra xem ký tự đầu tiên có phải là dấu nháy kép không
    // Nếu đúng, tiếp tục phân tích cú pháp chuỗi
    // Nếu không, trả về NULL
    if (**json == '\"') {
        (*json)++;
        const char *start = *json;
        while (**json != '\"' && **json != '\0') {
            (*json)++;
        }
        // Kiểm tra xem ký tự cuối cùng có phải là dấu nháy kép không
        // Nếu đúng, tạo một giá trị JSON với kiểu JSON_STRING
        // và giá trị tương ứng (chuỗi)
        // Nếu không, trả về NULL
        if (**json == '\"') {
            size_t length = *json - start; // 3
            char *str = (char *) malloc((length + 1) * sizeof(char));
            strncpy(str, start, length);
            str[length] = '\0';


            JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
            value->type = JSON_STRING;
            value->value.string = str;
            (*json)++;
            return value;
        }
    }
    return NULL;
}
```

Khi gặp ký tự ``'['``, chương trình nhảy vào function ``parse_array``:

```C
sonValue *parse_array(const char **json) {
    // Bỏ qua các ký tự trắng trong chuỗi JSON
    skip_whitespace(json);

    // Kiểm tra xem ký tự đầu tiên có phải là dấu ngoặc vuông mở không
    // Nếu đúng, tiếp tục phân tích cú pháp mảng
    // Nếu không, trả về NULL
    if (**json == '[') {
        (*json)++;
        skip_whitespace(json);

        JsonValue *array_value = (JsonValue *)malloc(sizeof(JsonValue));
        array_value->type = JSON_ARRAY;
        array_value->value.array.count = 0;
        array_value->value.array.values = NULL;

        /*
        double arr[2] = {};
        arr[0] = 30;
        arr[1] = 70;
        */

        // Phân tích cú pháp các phần tử trong mảng
        // Nếu gặp dấu phẩy, tiếp tục phân tích cú pháp phần tử tiếp theo
        // Nếu gặp dấu ngoặc vuông đóng, kết thúc phân tích cú pháp mảng
        // Nếu gặp lỗi, giải phóng bộ nhớ và trả về NULL
        while (**json != ']' && **json != '\0') {
            JsonValue *element = parse_json(json); // 70
            if (element) {
                array_value->value.array.count++;
                array_value->value.array.values = (JsonValue *)realloc(array_value->value.array.values, array_value->value.array.count * sizeof(JsonValue));
                array_value->value.array.values[array_value->value.array.count - 1] = *element;
                free(element);
            } else {
                break;
            }
            skip_whitespace(json);
            if (**json == ',') {
                (*json)++;
            }
        }
        if (**json == ']') {
            (*json)++;
            return array_value;
        } else {
            free_json_value(array_value);
            return NULL;
        }
    }
    return NULL;
}
```

Khi gặp ký tự ``'{'``, chương trình nhảy vào function ``parse_object``:

```C
JsonValue *parse_object(const char **json) {
    // Bỏ qua các ký tự trắng trong chuỗi JSON
    skip_whitespace(json);

    // Kiểm tra xem ký tự đầu tiên có phải là dấu ngoặc nhọn mở không
    // Nếu đúng, tiếp tục phân tích cú pháp đối tượng
    // Nếu không, trả về NULL
    if (**json == '{') {
        (*json)++;
        skip_whitespace(json);

        JsonValue *object_value = (JsonValue *)malloc(sizeof(JsonValue));
        object_value->type = JSON_OBJECT;
        object_value->value.object.count = 0;
        object_value->value.object.keys = NULL;
        object_value->value.object.values = NULL;


        // Phân tích cú pháp các cặp key-value trong đối tượng
        // Nếu gặp dấu phẩy, tiếp tục phân tích cú pháp cặp key-value tiếp theo
        // Nếu gặp dấu ngoặc nhọn đóng, kết thúc phân tích cú pháp đối tượng
        // Nếu gặp lỗi, giải phóng bộ nhớ và trả về NULL
        while (**json != '}' && **json != '\0') {
            JsonValue *key = parse_string(json);
            if (key) {
                skip_whitespace(json);
                if (**json == ':') {
                    (*json)++;
                    JsonValue *value = parse_json(json);
                    if (value) {
                        object_value->value.object.count++;
                        object_value->value.object.keys = (char **)realloc(object_value->value.object.keys, object_value->value.object.count * sizeof(char *));
                        object_value->value.object.keys[object_value->value.object.count - 1] = key->value.string;

                        object_value->value.object.values = (JsonValue *)realloc(object_value->value.object.values, object_value->value.object.count * sizeof(JsonValue));
                        object_value->value.object.values[object_value->value.object.count - 1] = *value;
                        free(value);
                    } else {
                        free_json_value(key);
                        break;
                    }
                } else {
                    free_json_value(key);
                    break;
                }
            } else {
                break;
            }
            skip_whitespace(json);
            if (**json == ',') {
                (*json)++;
            }
        }
        if (**json == '}') {
            (*json)++;
            return object_value;
        } else {
            free_json_value(object_value);
            return NULL;
        }
    }
    return NULL;
}
```

Nếu không phải các trường hợp trên, chương trình nhảy vào function ``parse_number``:

```C
JsonValue *parse_number(const char **json) {
    // Bỏ qua các ký tự trắng trong chuỗi JSON
    skip_whitespace(json);
    char *end;

    // Kiểm tra xem chuỗi có phải là số hay không
    // Nếu đúng, tạo một giá trị JSON với kiểu JSON_NUMBER
    // và giá trị tương ứng (số thực)
    // Nếu không, trả về NULL
    double num = strtod(*json, &end); // Chuyển đổi chuỗi thành số thực
    if (end != *json) {
        JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
        value->type = JSON_NUMBER;
        value->value.number = num;
        *json = end;
        return value;
    }
    return NULL;
}
```

Sau khi phân tích xong chuỗi Json, ta cần giải phóng bộ nhớ đã cung cấp cho chúng ``free_json_value``:

```C
void free_json_value(JsonValue *json_value) {
    if (json_value == NULL) {
        return;
    }

    switch (json_value->type) {
        case JSON_STRING:
            free(json_value->value.string);
            break;

        case JSON_ARRAY:
            for (size_t i = 0; i < json_value->value.array.count; i++) {
                free_json_value(&json_value->value.array.values[i]);
            }
            free(json_value->value.array.values);
            break;

        case JSON_OBJECT:
            for (size_t i = 0; i < json_value->value.object.count; i++) {
                free(json_value->value.object.keys[i]);
                free_json_value(&json_value->value.object.values[i]);
            }
            free(json_value->value.object.keys);
            free(json_value->value.object.values);
            break;

        default:
            break;
    }
}
```