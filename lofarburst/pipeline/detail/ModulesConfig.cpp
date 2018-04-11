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
#include "lofarburst/pipeline/ModulesConfig.h"


namespace lofarburst {
namespace pipeline {


template<typename PoolManagerType>
ModulesConfig<PoolManagerType>::ModulesConfig(PoolManagerType& pm)
    : ska::panda::ConfigModule("modules")
    , _pool_modules(pm, *this)
{
}

template<typename PoolManagerType>
ModulesConfig<PoolManagerType>::~ModulesConfig()
{
}

template<typename PoolManagerType>
void ModulesConfig<PoolManagerType>::add_options(OptionsDescriptionEasyInit&)
{
}

template<typename PoolManagerType>
template<typename T>
ska::panda::PoolSelector<PoolManagerType, T> const& ModulesConfig<PoolManagerType>::config() const { return _pool_modules.template config<T>(); }

} // namespace pipeline
} // namespace lofarburst
