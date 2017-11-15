/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ELEMENTS 5

#include "../testing/inc/main_test.h"
#define TEST

#include "../inc/ArrayList.h"
#include "../inc/Employee.h"




int run2(void);

int main(void)
{

    #ifdef TEST
        startTesting(1);//al_newArrayList ok
        startTesting(2);//al_add ok
        startTesting(3);//al_deleteArrayList ok
        startTesting(4);//al_len ok
        startTesting(5);//al_get ok
        startTesting(6);//al_contains ok
        startTesting(7);//al_set ok
        startTesting(8);//al_remove ok
        startTesting(9);//al_clear ok
        startTesting(10);//al_clone ok
        startTesting(11);//al_push ok
        startTesting(12);//al_indexOf ok
        startTesting(13);//al_isEmpty ok
        startTesting(14);//al_pop ok
        startTesting(15);//al_subList ok
        startTesting(16);//al_containsAll ok
        startTesting(17);//al_sort ok

    #endif

    return 0;
}

