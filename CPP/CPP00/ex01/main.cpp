/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:26:20 by brisly            #+#    #+#             */
/*   Updated: 2023/06/02 08:54:10 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdlib.h>
#include <limits.h>
#include "Contact.hpp"
#include "PhoneBook.hpp"

// https://stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-and-cin-ignore-after-reading-input 
// EXPLICATIONS pour .clear & .ignore

int ask_index(void)
{
    int index;
    
    std::cout << "> You can now select a contact by its index" << std::endl;
    if (std::cin >> index)
        return (index);
    else
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "\033[31m(ভ_ ভ) ރ Give me an integer and not a string !\033[0m" << std::endl;
        std::cin >> index;
    }
    return (index);
}

void search(PhoneBook &directory)
{
    int index;
    
    (void) index;
    std::cout << "⬇ -- Here's what's currently in the directory -- ⬇" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "|   Index   | First Name | Last Name| Nick Name |" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    directory.show_directory();
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "\n";
    index = ask_index();
}

void add(PhoneBook &directory)
{
    std::string fn, ln, nn, phone, secret;

    std::cout << " \033[95m⋆⸜(˙꒳​˙ )\033[0m Hello my dear ~ I need some information now...\n";
    std::cout << "> What is the first name of your contact ?" << std::endl;
    std::cin >> fn;
    std::cout << "> Its last name ?" << std::endl;
    std::cin >> ln;
    std::cout << "> What's its nickname ?" << std::endl;
    std::cin >> nn;
    std::cout << "> What's its phone number ?" << std::endl;
    std::cin >> phone;
    std::cout << "> If you know it... tell me its deepest secret" << std::endl;
    std::cin >> secret;
    std::cout << "> Contact added successfuly :). If you wanna search it now, just type SEARCH\n" << std::endl;
    directory.add_repertory(fn, ln, nn, phone, secret);
}

int main()
{
    std::string action;
    
    PhoneBook directory(0);

    std::cout << "\e[1;1H\e[2J";
    while (1)
    {
        std::cout << "\033[95m☏  Welcome in my PhoneBook ☏\033[0m" << std::endl;
        std::cout << "> What do you wanna do ? (SEARCH, ADD or EXIT) \n" << std::endl; //voir si on le demande pas que dans certains cas
        std::cin >> action;
        std::cout << std::endl;
        if (action == "ADD")
            add(directory);
        else if (action == "SEARCH")
            search(directory);
        else if (action == "EXIT"){
            std::cout << "> Thank you for using the funniest PhoneBook ever \033[95m(づ ᴗ _ᴗ)づ\033[0m" << std::endl;
            break;
        }
        else
            std::cout << "Only these actions are possible: ADD, SEARCH or EXIT.\n";
    }
    return (0);
}