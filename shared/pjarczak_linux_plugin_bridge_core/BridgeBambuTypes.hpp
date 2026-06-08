#pragma once

#if defined(PJARCZAK_LINUX_BRIDGE_STANDALONE_HOST)

#include <functional>
#include <map>
#include <string>

namespace Slic3r {

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
