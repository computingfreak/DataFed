#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include <map>
#include <stdint.h>
#include "SDMS.pb.h"
#include "MsgComm.hpp"

namespace SDMS {
namespace Core {


struct Config
{
    static Config & getInstance()
    {
        static Config inst;
        return inst;
    }

    //glob_xfr_url("https://transfer.api.globusonline.org/v0.10/"),

    Config():
        glob_oauth_url("https://auth.globus.org/v2/oauth2/"),
        glob_xfr_url("https://transfer.api.globus.org/v0.10/"),
        port(7512),
        timeout( 5 ),
        num_client_worker_threads( 4 ),
        num_task_worker_threads( 10 ),
        task_purge_age( 14*24*3600 ),
        task_purge_period( 6*3600 ),
        task_retry_time_fail( 3600 ),
        task_retry_time_init( 30 ), // Double every retry until max backoff
        task_retry_backoff_max( 4 ),
        repo_chunk_size( 100 ),
        repo_timeout( 60000 ),
        note_purge_age( 7*24*3600 ),
        note_purge_period( 6*3600 ),
        metrics_period( 300 ),
        metrics_purge_period( 3600 ),
        metrics_purge_age( 24*3600 )
    {}

    std::string     cred_dir;
    std::string     db_url;
    std::string     db_user;
    std::string     db_pass;
    std::string     glob_oauth_url;
    std::string     glob_xfr_url;
    std::string     client_id;
    std::string     client_secret;
    uint32_t        port;
    uint32_t        timeout;
    uint32_t        num_client_worker_threads;
    uint32_t        num_task_worker_threads;
    uint32_t        task_purge_age;
    uint32_t        task_purge_period;
    uint32_t        task_retry_time_fail;
    uint32_t        task_retry_time_init;
    uint32_t        task_retry_backoff_max;
    uint32_t        repo_chunk_size;
    uint32_t        repo_timeout;
    uint32_t        note_purge_age;
    uint32_t        note_purge_period;
    uint32_t        metrics_period;
    uint32_t        metrics_purge_period;
    uint32_t        metrics_purge_age;

    MsgComm::SecurityContext            sec_ctx;
    std::map<std::string,RepoData*>     repos;
};

}}

#endif
