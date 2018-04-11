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
#ifndef LOFARBURST_SOURCE_CONFIG_H
#define LOFARBURST_SOURCE_CONFIG_H

#include "lofarburst/source/udp/Config.h"
#include "lofarburst/utils/ConfigModule.h"
#include "cheetah/sigproc/Config.h"

namespace lofarburst {
namespace source {

/**
 * @brief
 * @details
 */

class Config : public utils::ConfigModule
{
    public:
        Config();
        ~Config();

        /**
         * @brief return the sigproc input data configuration
         */
        ska::cheetah::sigproc::Config const& sigproc_config() const;

        /**
         * @brief return the rcpt input data configuration
         */
        lofarburst::source::udp::Config const& udp_config() const;

        /**
         * @brief return the number of time spectrums in a chunk
         */
        unsigned spectrums_per_chunk() const;

        /**
         * @brief setthe number of time spectrums in a chunk
         */
        void spectrums_per_chunk(unsigned spectrums);

    protected:
        void add_options(OptionsDescriptionEasyInit& add_options) override;

    private:
        ska::cheetah::sigproc::Config _sigproc_config;
        lofarburst::source::udp::Config _udp_config;
        unsigned _spectrums_per_chunk;
};


} // namespace source
} // namespace lofarburst

#endif // LOFARBURST_SOURCE_CONFIG_H
