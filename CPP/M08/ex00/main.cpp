/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 23:52:47 by hthant            #+#    #+#             */
/*   Updated: 2025/09/09 00:02:14 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <easyfind.hpp>

int main() {
    std::vector<int> my_vector;
    my_vector.push_back(10);
    my_vector.push_back(20);
    my_vector.push_back(30);

    std::list<int> my_list;
    my_list.push_back(5);
    my_list.push_back(15);
    my_list.push_back(25);

    try { easyfind(my_vector, 20); } catch (const std::exception& e) { std::cerr << "Caught exception: " << e.what() << std::endl; }
    try { easyfind(my_vector, 40); } catch (const std::exception& e) { std::cerr << "Caught exception: " << e.what() << std::endl; }
    try { easyfind(my_list, 15); } catch (const std::exception& e) { std::cerr << "Caught exception: " << e.what() << std::endl; }
    try { easyfind(my_list, 50); } catch (const std::exception& e) { std::cerr << "Caught exception: " << e.what() << std::endl; }

    return 0;
}

