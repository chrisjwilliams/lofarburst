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
#ifndef LOFARBURST_PIPELINE_MODULESCONFIG_H
#define LOFARBURST_PIPELINE_MODULESCONFIG_H


#include "panda/ConfigModule.h"
#include "panda/PoolModuleConfig.h"
#include "cheetah/rfim/Config.h"
#include "cheetah/sps/Config.h"

namespace lofarburst {
namespace pipeline {

/**
 * @brief
 *   Class to contain all module configurations
 *
 * @details
 */

template<typename PoolManagerType>
class ModulesConfig : public ska::panda::ConfigModule
{
    public:
        ModulesConfig(PoolManagerType&);
        ~ModulesConfig();

        /// get the configuration for the specified module
        template<typename T>
        ska::panda::PoolSelector<PoolManagerType, T> const& config() const;

    protected:
        void add_options(OptionsDescriptionEasyInit& add_options) override;

    private:
        ska::panda::PoolModuleConfig<PoolManagerType
                                   , ska::cheetah::rfim::Config
                                   , ska::cheetah::sps::Config
                                    > _pool_modules;
};


} // namespace pipeline
} // namespace lofarburst
#include "detail/ModulesConfig.cpp"

#endif // LOFARBURST_PIPELINE_MODULESCONFIG_H
