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
#ifndef LOFARBURST_SOURCE_UDP_CONFIG_H
#define LOFARBURST_SOURCE_UDP_CONFIG_H


#include "lofarburst/utils/ConfigModule.h"
#include <panda/ProcessingEngine.h>
#include <panda/ProcessingEngineConfig.h>
#include <panda/EndpointConfig.h>
#include <panda/ProcessingEngine.h>
#include <panda/ProcessingEngineConfig.h>
#include <boost/asio.hpp>

namespace lofarburst {
namespace source {
class Config;
namespace udp {

/**
 * @brief
 * @details
 */

class Config : public utils::ConfigModule
{
    public:
        Config(source::Config const& parent);
        ~Config();

        ska::panda::Engine& engine() const;

       /**
         * @brief geters and setters for the UDP connection (IP address and port or remote peer)
         */
        boost::asio::ip::udp::endpoint remote_end_point() const;
        void remote_end_point(boost::asio::ip::udp::endpoint const& endpoint);

        /**
         * @brief return the number of time samples in a chunk
         */
        unsigned number_of_channels() const;

        /**
         * @brief return the number of complete spectrums in each TimeFrequency block
         */
        unsigned spectrums_per_chunk() const;

    protected:
        void add_options(OptionsDescriptionEasyInit& add_options) override;

    private:
        source::Config const& _parent;
        mutable std::unique_ptr<ska::panda::ProcessingEngine> _engine;
        ska::panda::ProcessingEngineConfig _engine_config;
        ska::panda::EndpointConfig _endpoint_config; // listen address;
};


} // namespace udp
} // namespace source
} // namespace lofarburst

#endif // LOFARBURST_SOURCE_UDP_CONFIG_H
