/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2018 Oxford Astrophysics
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "lofarburst/source/Factory.h"
#include "lofarburst/source/Config.h"
//#include "lofarburst/source/udp/UdpStream.h"
#include "lofarburst/pipeline/LofarburstConfiguration.h"
#include "lofarburst/pipeline/ProcessingPipeline.h"
#include "cheetah/sigproc/SigProcFileStream.h"

namespace lofarburst {
namespace source {

template<typename ComputeModule>
int Factory::exec(std::string const& stream_name, ComputeModule& runtime_handler)
{
    int rv=1;
    if(stream_name == "sigproc") {
        ska::cheetah::sigproc::SigProcFileStream data_stream(_config.source_config().sigproc_config());
        rv=lofarburst::pipeline::exec_pipeline(data_stream, runtime_handler);
        //rv=create_pipeline<ska::cheetah::sigproc::SigProcFileStream>(data_stream, _config, runtime_handler)->exec();
    }
    else if(stream_name == "udp") {
 //       udp::UdpStream data_stream(_config.source_config().udp_config());
 //       rv=lofarburst::pipeline::exec_pipeline(data_stream, runtime_handler);
    }
    else {
        std::cerr << "unknown stream type '" << stream_name << "'" << std::endl;
    }
    return rv;
}

} // namespace source
} // namespace lofarburst
