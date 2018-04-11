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
#include "lofarburst/source/udp/Config.h"
#include "lofarburst/source/Config.h"


namespace lofarburst {
namespace source {
namespace udp {


Config::Config(source::Config const& parent)
    : utils::ConfigModule("udp")
    , _parent(parent)
    , _endpoint_config("listen")
{
    _endpoint_config.address(ska::panda::IpAddress(53, "0.0.0.0"));
    add(_endpoint_config);
}

Config::~Config()
{
}

ska::panda::Engine& Config::engine() const
{
    if(!_engine) {
        _engine.reset(new ska::panda::ProcessingEngine(_engine_config));
    }
    return *_engine;
}

void Config::add_options(OptionsDescriptionEasyInit& /*add_options*/)
{
}

unsigned Config::number_of_channels() const
{
    return 16 * 256; // packets_per_spectrum * channels per packet
}

unsigned Config::spectrums_per_chunk() const
{
    return _parent.spectrums_per_chunk();
}

boost::asio::ip::udp::endpoint Config::remote_end_point() const
{
    return _endpoint_config.address().end_point<boost::asio::ip::udp::endpoint>();
}

void Config::remote_end_point(boost::asio::ip::udp::endpoint const& endpoint)
{
    _endpoint_config.address(ska::panda::IpAddress(endpoint));
}

} // namespace udp
} // namespace source
} // namespace lofarburst
