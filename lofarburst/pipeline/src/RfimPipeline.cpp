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
#include "lofarburst/pipeline/RfimPipeline.h"


namespace lofarburst {
namespace pipeline {


RfimPipeline::RfimPipeline(LofarburstConfiguration const& config, typename ProcessingPipeline::Exporter& exporter)
    : ProcessingPipeline(exporter)
    , _rfim_handler(*this)
    , _rfim(config.module_config<ska::cheetah::rfim::Config>() , _rfim_handler)
{
}

RfimPipeline::~RfimPipeline()
{
}

void RfimPipeline::operator()(TimeFrequencyType& data)
{
    _rfim.run(data);
}

RfimPipeline::RfimHandler::RfimHandler(RfimPipeline& p)
    : _pipeline(p)
{
}

void RfimPipeline::RfimHandler::operator()(TimeFrequencyType data)
{
    // send data to the exporter
    _pipeline.out().send(ska::panda::ChannelId("rfim"), data);
}

} // namespace pipeline
} // namespace lofarburst
