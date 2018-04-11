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
#include "lofarburst/source/Config.h"


namespace lofarburst {
namespace source {


Config::Config()
    : utils::ConfigModule("source")
    , _udp_config(*this)
    , _spectrums_per_chunk(2048)
{
    add(_sigproc_config);
    add(_udp_config);
}

Config::~Config()
{
}

void Config::add_options(OptionsDescriptionEasyInit& add_options)
{
    add_options
    ("spectrums_per_chunk", boost::program_options::value<unsigned>(&_spectrums_per_chunk)->default_value(_spectrums_per_chunk), "the number of individual spectrums in each chunk (number_of_spectrums x no_of_channels = total chunk size)")
    ;
}

ska::cheetah::sigproc::Config const& Config::sigproc_config() const
{
    return _sigproc_config;
}

lofarburst::source::udp::Config const& Config::udp_config() const
{
    return _udp_config;
}

unsigned Config::spectrums_per_chunk() const
{
    return _spectrums_per_chunk;
}

void Config::spectrums_per_chunk(unsigned num)
{
    _spectrums_per_chunk = num;
}

} // namespace source
} // namespace lofarburst
