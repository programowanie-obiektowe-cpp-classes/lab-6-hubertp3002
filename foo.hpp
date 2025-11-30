#pragma once

#include "Human.hpp"

#include <algorithm>
#include <list>
#include <vector>

std::vector< char > foo(std::list< Human >& people)
{
    std::vector< char > retval(people.size());

    std::for_each(people.begin(), people.end(), [](Human& h) { h.birthday(); });

    // U¿ycie std::transform do mapowania osób na znaki 'y'/'n' i jednoczesne
    // odwrócenie kolejnoœci.
    // std::rbegin() i std::rend() dla listy people daje nam iterator w odwrotnej
    // kolejnoœci, a std::back_inserter dla retval dodaje elementy na koniec.
    // Z uwagi na wymóg, ¿e kolejnoœæ znaków ma byæ odwrotna, ale wektor
    // ma byæ wype³niony od pocz¹tku do koñca, musimy u¿yæ std::copy i
    // odwróconych iteratorów (rbegin/rend) dla listy people, a jako
    // iterator docelowy u¿yæ begin() dla wektora retval.
    // To wype³ni retval w kolejnoœci od (n-1)-tej osoby do 0-wej osoby.

    // 0-ta osoba na liœcie -> (n-1)-ty element w wektorze
    // (n-1)-ta osoba na liœcie -> 0-ty element w wektorze

    std::transform(people.rbegin(), people.rend(), retval.begin(), [](const Human& h) {
        return h.isMonster() ? 'n' : 'y';
    });

    return retval;
}
