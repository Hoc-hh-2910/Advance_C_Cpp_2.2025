#include "..//Header/Json.h"-

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
 * @brief   Bỏ qua các ký tự trắng trong chuỗi JSON.
 * @param   json   Con trỏ đến chuỗi JSON đầu vào.
 * @return  void
 */
static void skip_whitespace(const char **json) {
    // Bỏ qua các ký tự trắng trong chuỗi JSON
    while (isspace(**json)) {
        (*json)++;
    }
}

/**
 * @brief   Phân tích cú pháp một giá trị JSON với giá trị là NULL.
 * @param   json   Con trỏ đến chuỗi JSON đầu vào.
 * @return  JsonValue*   Trả về con trỏ đến giá trị JSON đã phân tích cú pháp.
 */
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

/**
 * @brief   Phân tích cú pháp một giá trị JSON với giá trị là boolean.
 * @param   json   Con trỏ đến chuỗi JSON đầu vào.
 * @return  JsonValue*   Trả về con trỏ đến giá trị JSON đã phân tích cú pháp.
 */
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

/**
 * @brief   Phân tích cú pháp một giá trị JSON với giá trị là số.
 * @param   json   Con trỏ đến chuỗi JSON đầu vào.
 * @return  JsonValue*   Trả về con trỏ đến giá trị JSON đã phân tích cú pháp.
 */
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

/**
 * @brief   Phân tích cú pháp một giá trị JSON với giá trị là chuỗi.
 * @param   json   Con trỏ đến chuỗi JSON đầu vào.
 * @return  JsonValue*   Trả về con trỏ đến giá trị JSON đã phân tích cú pháp.
 */
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

/**
 * @brief   Phân tích cú pháp một giá trị JSON với giá trị là mảng.
 * @param   json   Con trỏ đến chuỗi JSON đầu vào.
 * @return  JsonValue*   Trả về con trỏ đến giá trị JSON đã phân tích cú pháp.
 */
JsonValue *parse_array(const char **json) {
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

/**
 * @brief   Phân tích cú pháp một giá trị JSON với giá trị là đối tượng.
 * @param   json   Con trỏ đến chuỗi JSON đầu vào.
 * @return  JsonValue*   Trả về con trỏ đến giá trị JSON đã phân tích cú pháp.
 */
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

/**
 * @brief   Phân tích cú pháp một giá trị JSON.
 * @param   json   Con trỏ đến chuỗi JSON đầu vào.
 * @return  JsonValue*   Trả về con trỏ đến giá trị JSON đã phân tích cú pháp.
 */
JsonValue *parse_json(const char **json) { 
    // Bỏ qua các ký tự trắng trong chuỗi JSON
    while (isspace(**json)) {
        (*json)++;
    }

    // Kiểm tra xem ký tự đầu tiên có phải là một trong các ký tự hợp lệ không
    // Nếu đúng, tiếp tục phân tích cú pháp giá trị JSON
    // Nếu không, trả về NULL
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
}

////////////

/////////////

/**
 * @brief   Giải phóng bộ nhớ cho giá trị JSON.
 * @param   json_value   Con trỏ đến giá trị JSON cần giải phóng.
 * @return  void
 */
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

/**
 * @brief   Hiển thị giá trị JSON.
 * @param   json_value   Con trỏ đến giá trị JSON cần hiển thị.
 * @return  void
 */
void test(JsonValue* json_value){
    if (json_value != NULL && json_value->type == JSON_OBJECT) {
        // Truy cập giá trị của các trường trong đối tượng JSON
        size_t num_fields = json_value->value.object.count;
        size_t num_fields2 = json_value->value.object.values->value.object.count;
        for (size_t i = 0; i < num_fields; ++i) {

            char* key = json_value->value.object.keys[i];
            JsonValue* value = &json_value->value.object.values[i];

            JsonType type = (int)(json_value->value.object.values[i].type);


            if(type == JSON_STRING){
                printf("%s: %s\n", key, value->value.string);
            }

            if(type == JSON_NUMBER){
                printf("%s: %f\n", key, value->value.number);
            }

            if(type == JSON_BOOLEAN){
                printf("%s: %s\n", key, value->value.boolean ? "True":"False");
            }

            if(type == JSON_OBJECT){
                printf("%s: \n", key);
                test(value);
            }

            if(type == JSON_ARRAY){
                printf("%s: ", key);
                for (int i = 0; i < value->value.array.count; i++)
                {
                   test(value->value.array.values + i);
                } 
                printf("\n");
            }

  
        }

     
    }
    else 
    {
            if(json_value->type == JSON_STRING){
                printf("%s ", json_value->value.string);
            }

            if(json_value->type == JSON_NUMBER){
                printf("%f ", json_value->value.number);
            }

            if(json_value->type == JSON_BOOLEAN){
                printf("%s ", json_value->value.boolean ? "True":"False");
            }

            if(json_value->type == JSON_OBJECT){
                printf("%s: \n", json_value->value.object.keys);
                test(json_value->value.object.values);
                           
            }
    }

}




int main(int argc, char const *argv[])
{
     // Chuỗi JSON đầu vào
    
    const char* json_str = "{"
                        "\"1001\":{"
                          "\"SoPhong\":3,"
                          "\"NguoiThue\":{"
                            "\"Ten\":\"Nguyen Van A\","
                            "\"CCCD\":\"1920517781\","
                            "\"Tuoi\":26,"
                            "\"ThuongTru\":{"
                              "\"Duong\":\"73 Ba Huyen Thanh Quan\","
                              "\"Phuong_Xa\":\"Phuong 6\","
                              "\"Tinh_TP\":\"Ho Chi Minh\""
                            "}"
                          "},"
                          "\"SoNguoiO\":{"
                            "\"1\":\"Nguyen Van A\","
                            "\"2\":\"Nguyen Van B\","
                            "\"3\":\"Nguyen Van C\""
                          "},"
                          "\"TienDien\": [24, 56, 98],"
                          "\"TienNuoc\":30.000"
                        "},"
                        "\"1002\":{"
                          "\"SoPhong\":5,"
                          "\"NguoiThue\":{"
                            "\"Ten\":\"Phan Hoang Trung\","
                            "\"CCCD\":\"012345678912\","
                            "\"Tuoi\":24,"
                            "\"ThuongTru\":{"
                              "\"Duong\":\"53 Le Dai Hanh\","
                              "\"Phuong_Xa\":\"Phuong 11\","
                              "\"Tinh_TP\":\"Ho Chi Minh\""
                            "}"
                          "},"
                          "\"SoNguoiO\":{"
                            "\"1\":\"Phan Van Nhat\","
                            "\"2\":\"Phan Van Nhi\","
                            "\"2\":\"Phan Van Tam\","
                            "\"3\":\"Phan Van Tu\""
                          "},"
                          "\"TienDien\":23.000,"
                          "\"TienNuoc\":40.000"
                        "}"
                      "}";
    

    // Phân tích cú pháp chuỗi JSON
    JsonValue* json_value = parse_json(&json_str);

    // Kiểm tra xem việc phân tích cú pháp có thành công hay không
    test(json_value);

    // Kiểm tra kết quả phân tích cú pháp

    // Giải phóng bộ nhớ được cấp phát cho JsonValue
    free_json_value(json_value);

        //printf("test = %x", '\"');

       // hienthi(5);
    
    return 0;
}


