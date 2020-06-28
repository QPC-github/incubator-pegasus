/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Microsoft Corporation
 *
 * -=- Robust Distributed System Nucleus (rDSN) -=-
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/*
 * Description:
 *     What is this file about?
 *
 * Revision history:
 *     xxxx-xx-xx, author, first version
 *     xxxx-xx-xx, author, fix bug about xxx
 */

#include "core/rpc/asio_net_provider.h"
#include <dsn/tool/providers.common.h>
#include "lockp.std.h"
#include "core/task/simple_task_queue.h"
#include "core/task/hpc_task_queue.h"
#include "core/rpc/network.sim.h"
#include "simple_logger.h"
#include "core/rpc/dsn_message_parser.h"
#include "core/rpc/thrift_message_parser.h"
#include "core/rpc/raw_message_parser.h"

namespace dsn {
namespace tools {
void register_common_providers()
{
    register_component_provider<env_provider>("dsn::env_provider");
    register_component_provider<task_worker>("dsn::task_worker");
    register_component_provider<screen_logger>("dsn::tools::screen_logger");
    register_component_provider<simple_logger>("dsn::tools::simple_logger");

    register_std_lock_providers();

    register_component_provider<asio_network_provider>("dsn::tools::asio_network_provider");
    register_component_provider<asio_udp_provider>("dsn::tools::asio_udp_provider");
    register_component_provider<sim_network_provider>("dsn::tools::sim_network_provider");
    register_component_provider<simple_task_queue>("dsn::tools::simple_task_queue");
    register_component_provider<hpc_concurrent_task_queue>("dsn::tools::hpc_concurrent_task_queue");
    register_component_provider<simple_timer_service>("dsn::tools::simple_timer_service");

    register_message_header_parser<dsn_message_parser>(NET_HDR_DSN, {"RDSN"});
    register_message_header_parser<thrift_message_parser>(NET_HDR_THRIFT, {"THFT"});
    register_message_header_parser<raw_message_parser>(NET_HDR_RAW, {"_RAW"});
}
} // namespace tools
} // namespace dsn
