/**
*
* Copyright (C) 2014-2018    Andrei Novikov (pyclustering@yandex.ru)
*
* GNU_PUBLIC_LICENSE
*   pyclustering is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   pyclustering is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/

#include "interface/kmeans_interface.h"

#include "cluster/kmeans.hpp"


pyclustering_package * kmeans_algorithm(const pyclustering_package * const p_sample, const pyclustering_package * const p_initial_centers, const double p_tolerance) {
    dataset data, centers;

    p_sample->extract(data);
    p_initial_centers->extract(centers);

    ccore::clst::kmeans algorithm(centers, p_tolerance);

    ccore::clst::kmeans_data output_result;
    algorithm.process(data, output_result);

    pyclustering_package * package = create_package(output_result.clusters().get());
    return package;
}
