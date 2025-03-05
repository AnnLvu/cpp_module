/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:54:18 by alvutina          #+#    #+#             */
/*   Updated: 2025/02/06 12:54:19 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

template <typename T>
typename T::iterator easyfind(T &container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::runtime_error("Value not found in container");
    }
    return it;
}

#endif
