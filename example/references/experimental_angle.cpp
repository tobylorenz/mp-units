// The MIT License (MIT)
//
// Copyright (c) 2018 Mateusz Pusz
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <units/bits/external/hacks.h>  // IWYU pragma: keep

UNITS_DIAGNOSTIC_PUSH
UNITS_DIAGNOSTIC_IGNORE_SHADOW
#include <units/isq/si/force.h>  // 'N' (Newton) shadows a template parameter traditionally used as a size of the array
UNITS_DIAGNOSTIC_POP

#include <units/generic/angle.h>
#include <units/isq/si/energy.h>
#include <units/isq/si/length.h>
#include <units/isq/si/torque.h>  // IWYU pragma: keep
#include <units/quantity_io.h>
#include <iostream>

int main()
{
  using namespace units;
  using namespace units::isq;
  using namespace units::isq::si::references;
  using namespace units::references;

  Torque auto torque = 20.0 / std::numbers::pi * (N * m / rad);
  Energy auto energy = 20.0 * J;

  Angle auto angle = energy / torque;

  std::cout << angle << '\n';
  std::cout << quantity_cast<rotation>(angle) << '\n';
  std::cout << quantity_cast<degree>(angle) << '\n';
  std::cout << quantity_cast<gradian>(angle) << '\n';
}
