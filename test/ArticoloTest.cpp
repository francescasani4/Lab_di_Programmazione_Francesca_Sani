//
// Created by Francesca Sani
//

#include "gtest/gtest.h"
#include "../Articolo.h"

TEST(ArticoloSuite, TestCostruttore) {
    Articolo art1("Pasta", "Cibo", 3);

    ASSERT_EQ(art1.getIDarticolo(), "Pasta");
    ASSERT_EQ(art1.getCat(), "Cibo");
    ASSERT_EQ(art1.getQt(), 3);

    ASSERT_THROW(Articolo art2("Insalata", "Cibo", -4), invalid_argument);
}

TEST(ArticoloSuite, TestGetAndSet) {
    Articolo articolo("Prova", "Cibo", 5);

    articolo.setIDarticolo("Salsiccia");
    ASSERT_EQ(articolo.getIDarticolo(), "Salsiccia");

    articolo.setCat("Carne");
    ASSERT_EQ(articolo.getCat(), "Carne");

    articolo.setQt(10);
    ASSERT_EQ(articolo.getQt(), 10);
}