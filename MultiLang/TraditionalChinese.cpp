#include "MultiLang.h"

static constexpr MultiLang::string bb_err = "Blitz錯誤";
static constexpr MultiLang::string init_err = "啟動BlitzIDE時出錯。請檢查\"bin\"文件夾內是否有ide.exe。";
static constexpr MultiLang::string array_bounds_ex = "Blitz數組索引越界";
static constexpr MultiLang::string null_obj_ex = "對象不存在";
static constexpr MultiLang::string bad_data_type = "錯誤的數據類型！數據類型不應是浮點值、字符串或整型";
static constexpr MultiLang::string out_of_data = "數據不足";
static constexpr MultiLang::string stats_strings = "激活的字符串：{0}";
static constexpr MultiLang::string stats_objects = "激活的對象：{0}";
static constexpr MultiLang::string stats_unreleased = "未釋放的對象：{0}";
static constexpr MultiLang::string sound_not_exist = "聲音不存在";
static constexpr MultiLang::string bank_not_exist = "bbBank不存在";
static constexpr MultiLang::string offset_out_of_range = "位置超出範圍";
static constexpr MultiLang::string graphics_not_set = "3D畫面模式未設置";
static constexpr MultiLang::string texture_not_exist = "紋理不存在";
static constexpr MultiLang::string brush_not_exist = "Brush不存在";
static constexpr MultiLang::string entity_not_exist = "實體不存在";
static constexpr MultiLang::string parent_entity_not_exist = "父實體不存在";
static constexpr MultiLang::string entity_not_mesh = "實體不是Mesh";
static constexpr MultiLang::string entity_not_object = "實體不是對象";
static constexpr MultiLang::string collision_out_of_range = "碰撞索引超出範圍";
static constexpr MultiLang::string entity_not_camera = "實體不是相機";
static constexpr MultiLang::string entity_not_light = "實體不是燈光";
static constexpr MultiLang::string entity_not_model = "實體不是模型";
static constexpr MultiLang::string entity_not_sprite = "實體不是Sprite";
static constexpr MultiLang::string entity_not_md2_model = "實體不是MD2模型";
static constexpr MultiLang::string entity_not_bsp_model = "實體不是BSP模型";
static constexpr MultiLang::string entity_not_terrain = "實體不是地形";
static constexpr MultiLang::string illegal_number_segments = "段數非法";
static constexpr MultiLang::string vertex_out_of_range = "頂點索引超出範圍";
static constexpr MultiLang::string texture_coordinate_out_of_range = "紋理座標設置超出範圍";
static constexpr MultiLang::string illegal_texture_frames = "非法紋理幀數";
static constexpr MultiLang::string mesh_cannot_add_to_self = "無法將Mesh添加到其本身";
static constexpr MultiLang::string surface_out_of_range = "表面索引超出範圍";
static constexpr MultiLang::string illegal_terrain_size = "非法地形大小";
static constexpr MultiLang::string unable_load_heightmap = "無法加載高度圖";
static constexpr MultiLang::string terrain_must_be_square = "地表必須為正方形";
static constexpr MultiLang::string listener_already_created = "已創建監聽器";
static constexpr MultiLang::string no_listener_created = "未創建監聽器";
static constexpr MultiLang::string entity_cannot_parented_itself = "實體不能為其自身的父實體";
static constexpr MultiLang::string entity_no_animations = "實體無動畫";
static constexpr MultiLang::string entity_not_model_or_camera = "實體不是模型或相機";
static constexpr MultiLang::string entitytype_id_range = "EntityType ID必須為0至999之間的數字";
static constexpr MultiLang::string unable_create_gxscene_instance = "無法創建gxScene實例";
static constexpr MultiLang::string file_not_exist = "文件不存在";
static constexpr MultiLang::string directory_not_exist = "文件夾不存在";
static constexpr MultiLang::string image_not_exist = "圖像不存在";
static constexpr MultiLang::string image_frame_out_of_range = "圖像幀超出範圍";
static constexpr MultiLang::string font_not_exist = "字體不存在";
static constexpr MultiLang::string buffer_not_exist = "緩衝區不存在";
static constexpr MultiLang::string illegal_graphics_driver_index = "非法顯示驅動索引";
static constexpr MultiLang::string illegal_graphics_mode_index = "非法顯示模式索引";
static constexpr MultiLang::string unable_create_gxgraphics_instance = "無法創建gxGraphics實例";
static constexpr MultiLang::string illegal_graphics_mode = "非法顯示模式，顯示模式為0到7之間的值。";
static constexpr MultiLang::string illegal_graphics3d_mode = "非法3D顯示模式，顯示模式為0到7之間的值。";
static constexpr MultiLang::string unable_close_gxgraphics_instance = "無法關閉gxGraphics實例";
static constexpr MultiLang::wstring runtime_error = L"運行時錯誤！";
static constexpr MultiLang::wstring opencc_configure_not_found = L"找不到OpenCC設置！";
static constexpr MultiLang::string illegal_frame_count = "非法幀數";
static constexpr MultiLang::string illegal_first_frame = "非法第一幀";
static constexpr MultiLang::string not_enough_frames_bitmap = "位圖幀數不足";
static constexpr MultiLang::string udp_stream_not_exist = "UDP流不存在";
static constexpr MultiLang::string tcp_stream_not_exist = "TCP流不存在";
static constexpr MultiLang::string tcp_server_not_exist = "TCP服務器不存在";
static constexpr MultiLang::string host_out_of_range = "主機索引超出範圍";
static constexpr MultiLang::string stream_not_exist = "流不存在";
static constexpr MultiLang::string readbyte_invalid_byte = "ReadByte無法讀取有效字節\n請確保讀取的文件尚未損壞";
static constexpr MultiLang::string readshort_invalid_short = "ReadShort無法讀取有效短整型\n請確保讀取的文件尚未損壞";
static constexpr MultiLang::string readint_invalid_int = "ReadInt無法讀取有效整型\n請確保讀取的文件尚未損壞";
static constexpr MultiLang::string readfloat_invalid_float = "ReadFloat無法讀取有效浮點值\n請確保讀取的文件尚未損壞";
static constexpr MultiLang::string readstring_invalid_string = "ReadString無法讀取有效字符串\n請確保讀取的文件尚未損壞";
static constexpr MultiLang::string illegal_buffer_size = "非法緩衝區大小";
static constexpr MultiLang::string string_parameter_positive = "{0}：參數必須為正";
static constexpr MultiLang::string string_parameter_greater = "{0}：參數必須大於0";
static constexpr MultiLang::string userlib_not_found = "用戶庫未找到";
static constexpr MultiLang::string userlib_function_not_found = "用戶庫函數未找到";
static constexpr MultiLang::wstring integer_divide_zero = L"整數除零";
static constexpr MultiLang::wstring memory_access_violation = L"內存訪問衝突！\n程序試圖讀取或寫入受保護的內存地址。";
static constexpr MultiLang::wstring illegal_instruction = L"非法指令。\n程序試圖執行無效的CPU指令";
static constexpr MultiLang::wstring stack_overflow = L"堆棧溢出！\n請確保程序內沒有遞歸現象";
static constexpr MultiLang::wstring integer_overflow = L"整數溢出！\n請確保整數的值不超過2147483647";
static constexpr MultiLang::wstring float_overflow = L"浮點溢出！\n請確保浮點的值不超過3.40282347e+38F";
static constexpr MultiLang::wstring float_divide_zero = L"浮點除零";
static constexpr MultiLang::wstring unknown_runtime_exception = L"未知運行時錯誤";
static constexpr MultiLang::string unable_run_module = "無法啟動Blitz Basic模塊";
static constexpr MultiLang::string cant_find_symbol = "找不到符號：{0}";
static constexpr MultiLang::string blitz3d_message = "Blitz3D消息";
static constexpr MultiLang::string created_with_beta = "使用Blitz3D Beta V{0}.{1}製作";
static constexpr MultiLang::string expect_identifier = "\".\"後應為標識符";
static constexpr MultiLang::string expect_string_afrer_directive = "lib指令後應為字符串";
static constexpr MultiLang::string unknown_decl_directive = "未知庫指令";
static constexpr MultiLang::string function_decl_without_directive = "無lib的函數庫";
static constexpr MultiLang::string duplicate_identifier = "重複標識符";
static constexpr MultiLang::string expect_left_bracket_after_function_identifier = "函數名後缺少\"(\"";
static constexpr MultiLang::string expect_right_bracket_after_function_identifier = "函數參數後缺少\")\"";
static constexpr MultiLang::string expect_identifier_or_string_after_alias = "別名後應為標識符或字符串";
static constexpr MultiLang::string unable_open_linker_dll = "無法打開linker.dll";
static constexpr MultiLang::string error_in_linker_dll = "linker.dll出錯";
static constexpr MultiLang::string unable_open_runtime_dll = "無法打開runtime.dll";
static constexpr MultiLang::string error_in_runtime_dll = "runtime.dll出錯";
static constexpr MultiLang::string library_version_error = "庫版本出錯";
static constexpr MultiLang::string immediate_value_cannot_by_label = "立即值不能通過標籤";
static constexpr MultiLang::string operand_must_be_immediate = "操作數必須為立即數";
static constexpr MultiLang::string unrecognized_instruction = "未識別指令";
static constexpr MultiLang::string illegal_addressing_mode = "非法尋地址方式";
static constexpr MultiLang::string operand_error = "操作數誤差";
static constexpr MultiLang::string duplicate_label = "重複標籤";
static constexpr MultiLang::string missing_close_quote = "缺失後引號";
static constexpr MultiLang::string expect_comma = "缺少\",\"";
static constexpr MultiLang::string too_many_operands = "操作數過多";
static constexpr MultiLang::string expression_must_be_constant = "表達式必須為常數";
static constexpr MultiLang::string constants_must_initialized = "常數必須被初始化";
static constexpr MultiLang::string duplicate_variable_name = "重複變量名";
static constexpr MultiLang::string undefined_label = "未定義標籤";
static constexpr MultiLang::string data_expression_must_be_constant = "數據表達式必須為常數";
static constexpr MultiLang::string blitz_array_sizes_must_be_constant = "Blitz數組大小必須為常數";
static constexpr MultiLang::string blitz_array_sizes_must_not_negative = "Blitz數組大小不能為負數";
static constexpr MultiLang::string illegal_type_conversion = "非法類型轉換（{0} -> {1}）";
static constexpr MultiLang::string too_many_parameters = "參數過多";
static constexpr MultiLang::string not_enough_parameters = "參數過少";
static constexpr MultiLang::string function_not_found = "函數\"{0}\"未找到";
static constexpr MultiLang::string incorrect_function_return_type = "錯誤函數返回值";
static constexpr MultiLang::string cant_convert_null_to_int = "不能將null轉為整數";
static constexpr MultiLang::string cant_convert_null_to_float = "不能將null轉為浮點值";
static constexpr MultiLang::string cant_convert_null_to_string = "不能將null轉為字符串";
static constexpr MultiLang::string illegal_operator_for_type = "非法類型運算符";
static constexpr MultiLang::string arithmetic_operator_custom_type = "算術運算符不能用於自定類型對象";
static constexpr MultiLang::string operator_cannot_applied_to_strings = "運算符不能用於字符串";
static constexpr MultiLang::string division_by_zero = "數字除零";
static constexpr MultiLang::string custom_type_not_found = "自定類型名未找到";
static constexpr MultiLang::string type_is_not_custom_type = "類型不是自定類型";
static constexpr MultiLang::string after_cannot_used_on_null = "\"After\"不能用於\"Null\"";
static constexpr MultiLang::string after_must_used_with_custom_type = "\"After\"必須和自定類型對象使用";
static constexpr MultiLang::string before_cannot_used_with_null = "\"Before\"不能用於\"Null\"";
static constexpr MultiLang::string before_must_used_with_custom_type = "\"Before\"必須和自定類型對象使用";
static constexpr MultiLang::string objecthandle_must_used_with_object = "\"ObjectHandle\"必須和對象使用";
static constexpr MultiLang::string internal_compiler_error = "編譯器內部錯誤！";
static constexpr MultiLang::string type_not_found = "類型\"{0}\"未找到";
static constexpr MultiLang::string error_in_operand = "操作數錯誤";
static constexpr MultiLang::string illegal_operand_size = "非法操作數大小";
static constexpr MultiLang::string register_must_be_32_bit = "寄存器必須為32位";
static constexpr MultiLang::string next_without_for = "\"Next\"缺少\"For\"";
static constexpr MultiLang::string wend_without_while = "\"Wend\"缺少\"While\"";
static constexpr MultiLang::string else_without_if = "\"Else\"缺少\"If\"";
static constexpr MultiLang::string endif_without_if = "\"Endif\"缺少\"If\"";
static constexpr MultiLang::string end_function_without_function = "\"End Function\"缺少\"Function\"";
static constexpr MultiLang::string until_without_repeat = "\"Until\"缺少\"Repeat\"";
static constexpr MultiLang::string forever_without_repeat = "\"Forever\"缺少\"Repeat\"";
static constexpr MultiLang::string case_without_select = "\"Case\"缺少\"Select\"";
static constexpr MultiLang::string end_select_without_select = "\"End Select\"缺少\"Select\"";
static constexpr MultiLang::string expecting = "缺少{0}";
static constexpr MultiLang::string identifier = "標識符";
static constexpr MultiLang::string include_filename = "導入文件名";
static constexpr MultiLang::string unable_open_include_file = "無法打開導入文件";
static constexpr MultiLang::string end_of_file = "文件尾部（EOF）";
static constexpr MultiLang::string mismatched_brackets = "括號不匹配";
static constexpr MultiLang::string variable_assignment = "變量賦值";
static constexpr MultiLang::string until_or_forever = "\"Until\"或\"Forever\"";
static constexpr MultiLang::string expression_sequence = "表達式序列";
static constexpr MultiLang::string case_default_or_end_select = "\"Case\"、\"Default\"或\"End Select\"";
static constexpr MultiLang::string before_or_after = "\"Before\"或\"After\"";
static constexpr MultiLang::string data_can_only_appear_in_main = "\"Data\"只能在主程序出現";
static constexpr MultiLang::string type_can_only_appear_in_main = "\"Type\"只能在主程序出現";
static constexpr MultiLang::string const_can_only_appear_in_main = "\"Const\"只能在主程序出現";
static constexpr MultiLang::string function_can_only_appear_in_main = "\"Function\"只能在主程序出現";
static constexpr MultiLang::string global_can_only_appear_in_main = "\"Global\"只能在主程序出現";
static constexpr MultiLang::string blitz_arrays_may_not_be_constant = "Blitz數組不能為常量";
static constexpr MultiLang::string cant_have_zero_dimension_array = "不能有零維數組";
static constexpr MultiLang::string field_or_end_type = "\"Field\"或\"End Type\"";
static constexpr MultiLang::string expression = "表達式";
static constexpr MultiLang::string undefined_label_check = "未聲明標籤\"{0}\"";
static constexpr MultiLang::string array_not_found_in_main = "在主程序中找不到數組";
static constexpr MultiLang::string constants_can_not_assigned_to = "不能將常量分配給";
static constexpr MultiLang::string blitz_arrays_can_not_assigned_to = "不能將Blitz數組分配給";
static constexpr MultiLang::string gosub_may_not_used_inside_function = "\"Gosub\"不能在函數內使用";
static constexpr MultiLang::string break_must_appear_inside_loop = "break必須在循環中出現";
static constexpr MultiLang::string index_variable_can_not_constant = "索引變量不能為常量";
static constexpr MultiLang::string index_variable_must_integer_or_real = "索引變量必須為整數或實數";
static constexpr MultiLang::string step_value_must_constant = "步進值必須為常量";
static constexpr MultiLang::string index_variable_is_not_newtype = "索引變量不是新類型";
static constexpr MultiLang::string type_name_not_found = "類型名未找到";
static constexpr MultiLang::string type_mismatch = "類型不匹配";
static constexpr MultiLang::string main_cannot_return_value = "主程序不能返回值";
static constexpr MultiLang::string cant_delete_non_newtype = "不能刪除非新類型";
static constexpr MultiLang::string specified_name_is_not_newtype_name = "指定名稱不是新類型名";
static constexpr MultiLang::string illegal_expression_type = "非法表達式類型";
static constexpr MultiLang::string objects_types_are_different = "對量類型不同";
static constexpr MultiLang::string select_cannot_used_with_objects = "Select不能用於對象";
static constexpr MultiLang::string constants_can_not_modified = "常量不可被修改";
static constexpr MultiLang::string data_can_not_read_into_object = "無法將數據讀入Object";
static constexpr MultiLang::string variable_type_mismatch = "變量類型不匹配";
static constexpr MultiLang::string identifier_not_used_like_this = "標識符\"{0}\"不允許如此使用";
static constexpr MultiLang::string array_not_found = "數組未找到";
static constexpr MultiLang::string array_type_mismatch = "數組類型不匹配";
static constexpr MultiLang::string incorrect_number_of_dimensions = "錯誤維度數字";
static constexpr MultiLang::string variable_must_be_type = "變量必須為類型";
static constexpr MultiLang::string type_field_not_found = "類型數據未找到";
static constexpr MultiLang::string variable_must_a_blitz_array = "變量必須為Blitz數組";
static constexpr MultiLang::string incorrect_number_of_subscripts = "下標數出錯";
static constexpr MultiLang::string blitz_array_subscript_out_of_range = "Blitz數組下標超出範圍";
static constexpr MultiLang::wstring runtime_message = L"運行時消息";
static constexpr MultiLang::string current_language = "當前語言：簡體中文\r\n\r\n";
static constexpr MultiLang::string debugger_locals = "本地";
static constexpr MultiLang::string debugger_globals = "全局";
static constexpr MultiLang::string debugger_consts = "常量";
static constexpr MultiLang::string debugger_unknown = "<未知>";
static constexpr MultiLang::string debugger_cant_access_appdata = "無法訪問AppData文件夾！配置文件無法讀取。\nIDE將使用默認值";
static constexpr MultiLang::string debugger_cant_create_folder = "無法為配置文件創建文件夾！\nIDE將使用默認值";
static constexpr MultiLang::string debugger_empty_ini = "blitzide.ini為空！\n將使用默認設置";
static constexpr char credits[] =
"編程及設計：Mark Sibly\r\n"
"項目續命：juanjp600、Saalvage、VaneBrain、AestheticalZ和ZiYueCommentary\r\n"
".INI加載器使用\"IniPP\"的修改版本，原版由Matthias C. M. Troffaes製作\r\n"
"文檔：Mark Sibly、Simon Harrison、Paul Gerfen、Shane Monroe和Blitz文檔撰寫團隊\r\n"
"測試及支持：James Boyd、Simon Armstrong和Blitz開發團隊\r\n"
"圖像加載器：Floris van den berg製作的FreeImage\r\n";
static constexpr MultiLang::string title_release = " - 發佈版本\n\n";
static constexpr MultiLang::string unable_start_program = "無法啟動程序！無法啟動所需模塊";
static constexpr MultiLang::string program_ended = "程序已結束";
static constexpr MultiLang::string unknown_exception_thrown = "未知/非標準異常拋出！";
static constexpr MultiLang::string startup_error = "啟動錯誤：{0}";