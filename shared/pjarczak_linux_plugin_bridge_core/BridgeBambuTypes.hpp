#pragma once

#if defined(PJARCZAK_LINUX_BRIDGE_STANDALONE_HOST)

#include <functional>
#include <map>
#include <string>

namespace Slic3r {

#define BAMBU_NETWORK_SUCCESS                           0
#define BAMBU_NETWORK_ERR_INVALID_HANDLE                -1
#define BAMBU_NETWORK_ERR_CONNECT_FAILED                -2
#define BAMBU_NETWORK_ERR_DISCONNECT_FAILED             -3
#define BAMBU_NETWORK_ERR_SEND_MSG_FAILED               -4
#define BAMBU_NETWORK_ERR_BIND_FAILED                   -5
#define BAMBU_NETWORK_ERR_UNBIND_FAILED                 -6
#define BAMBU_NETWORK_ERR_REQUEST_SETTING_FAILED        -7
#define BAMBU_NETWORK_ERR_PUT_SETTING_FAILED            -8
#define BAMBU_NETWORK_ERR_GET_SETTING_LIST_FAILED       -9
#define BAMBU_NETWORK_ERR_DEL_SETTING_FAILED            -10
#define BAMBU_NETWORK_ERR_GET_USER_PRINTINFO_FAILED     -11
#define BAMBU_NETWORK_ERR_QUERY_BIND_INFO_FAILED        -12
#define BAMBU_NETWORK_ERR_MODIFY_PRINTER_NAME_FAILED    -13
#define BAMBU_NETWORK_ERR_FILE_NOT_EXIST                -14
#define BAMBU_NETWORK_ERR_FILE_OVER_SIZE                -15
#define BAMBU_NETWORK_ERR_CHECK_MD5_FAILED              -16
#define BAMBU_NETWORK_ERR_TIMEOUT                       -17
#define BAMBU_NETWORK_ERR_CANCELED                      -18
#define BAMBU_NETWORK_ERR_INVALID_RESULT                -19
#define BAMBU_NETWORK_ERR_FTP_UPLOAD_FAILED             -20
#define BAMBU_NETWORK_ERR_GET_RATING_ID_FAILED          -21
#define BAMBU_NETWORK_ERR_OPEN_FILE_FAILED              -22
#define BAMBU_NETWORK_ERR_PARSE_CONFIG_FAILED           -23
#define BAMBU_NETWORK_ERR_NO_CORRESPONDING_BUCKET       -24
#define BAMBU_NETWORK_ERR_GET_INSTANCE_ID_FAILED        -25
#define BAMBU_NETWORK_SIGNED_ERROR                      -26

#define BAMBU_NETWORK_ERR_BIND_CREATE_SOCKET_FAILED          -1010
#define BAMBU_NETWORK_ERR_BIND_SOCKET_CONNECT_FAILED         -1020
#define BAMBU_NETWORK_ERR_BIND_PUBLISH_LOGIN_REQUEST         -1030
#define BAMBU_NETWORK_ERR_BIND_GET_PRINTER_TICKET_TIMEOUT    -1040
#define BAMBU_NETWORK_ERR_BIND_GET_CLOUD_TICKET_TIMEOUT      -1050
#define BAMBU_NETWORK_ERR_BIND_POST_TICKET_TO_CLOUD_FAILED   -1060
#define BAMBU_NETWORK_ERR_BIND_PARSE_LOGIN_REPORT_FAILED     -1070
#define BAMBU_NETWORK_ERR_BIND_ECODE_LOGIN_REPORT_FAILED     -1080
#define BAMBU_NETWORK_ERR_BIND_RECEIVE_LOGIN_REPORT_TIMEOUT  -1090

typedef std::function<void(std::string topic_str)> OnPrinterConnectedFn;
typedef std::function<void(int status, std::string dev_id, std::string msg)> OnLocalConnectedFn;
typedef std::function<void(int return_code, int reason_code)> OnServerConnectedFn;
typedef std::function<void(std::string dev_id, std::string msg)> OnMessageFn;
typedef std::function<void(unsigned http_code, std::string http_body)> OnHttpErrorFn;
typedef std::function<std::string()> GetCountryCodeFn;
typedef std::function<void(std::string topic)> GetSubscribeFailureFn;
typedef std::function<void(int status, int code, std::string msg)> OnUpdateStatusFn;
typedef std::function<bool()> WasCancelledFn;
typedef std::function<bool(int status, std::string job_info)> OnWaitFn;
typedef std::function<void(std::string dev_info_json_str)> OnMsgArrivedFn;
typedef std::function<void(std::function<void()>)> QueueOnMainFn;
typedef std::function<void(int progress)> ProgressFn;
typedef std::function<bool(std::map<std::string, std::string> info)> CheckFn;
typedef std::function<void(std::string url, int status)> OnServerErrFn;
typedef std::function<void(int online_login, bool login)> OnUserLoginFn;

struct detectResult {
    std::string result_msg;
    std::string command;
    std::string dev_id;
    std::string model_id;
    std::string dev_name;
    std::string version;
    std::string bind_state;
    std::string connect_type;
};

struct PrintParams {
    std::string dev_id;
    std::string task_name;
    std::string project_name;
    std::string preset_name;
    std::string filename;
    std::string config_filename;
    int plate_index{0};
    std::string ftp_folder;
    std::string ftp_file;
    std::string ftp_file_md5;
    std::string nozzle_mapping;
    std::string ams_mapping;
    std::string ams_mapping2;
    std::string ams_mapping_info;
    std::string nozzles_info;
    std::string connection_type;
    std::string comments;
    int origin_profile_id{0};
    int stl_design_id{0};
    std::string origin_model_id;
    std::string print_type;
    std::string dst_file;
    std::string dev_name;
    std::string dev_ip;
    bool use_ssl_for_ftp{false};
    bool use_ssl_for_mqtt{false};
    std::string username;
    std::string password;
    bool task_bed_leveling{false};
    bool task_flow_cali{false};
    bool task_vibration_cali{false};
    bool task_layer_inspect{false};
    bool task_record_timelapse{false};
    bool task_use_ams{false};
    std::string task_bed_type;
    std::string extra_options;
    int auto_bed_leveling{0};
    int auto_flow_cali{0};
    int auto_offset_cali{0};
    int extruder_cali_manual_mode{-1};
    bool task_ext_change_assist{false};
    bool try_emmc_print{false};
};

struct TaskQueryParams {
    std::string dev_id;
    int status{0};
    int offset{0};
    int limit{20};
};

struct PublishParams {
    std::string project_name;
    std::string project_3mf_file;
    std::string preset_name;
    std::string project_model_id;
    std::string design_id;
    std::string config_filename;
};

}

#else

#include "../../src/slic3r/Utils/bambu_networking.hpp"

namespace Slic3r {
typedef std::function<void(int online_login, bool login)> OnUserLoginFn;
}

#endif

namespace BBL = Slic3r;
