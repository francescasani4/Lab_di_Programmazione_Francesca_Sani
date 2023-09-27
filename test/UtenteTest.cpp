//
// Created by Francesca Sani
//

#include "gtest/gtest.h"
#include "../Lista.h"
#include "../Utente.h"

class UtenteSuite : public ::testing::Test {
protected:
    void SetUp() override {
        utente.aggiungiLista(&lista1);
        utente.aggiungiLista(&lista2);
    }

    Utente utente{"Francesca"};
    Lista lista1{"Casa"};
    Lista lista2{"Lavoro"};
    Lista lista3{"Hobby"};
};

TEST_F(UtenteSuite, TestGetIDutente) {
    ASSERT_EQ(utente.getIDutente(), "Francesca");
}

TEST_F(UtenteSuite, TestSetIDutente) {
    utente.setIDutente("Alessia");

    ASSERT_EQ(utente.getIDutente(), "Alessia");
}

TEST_F(UtenteSuite, TestAggiugniLista) {
    utente.aggiungiLista(&lista3);

    ASSERT_EQ(utente.getListe().size(), 3);
}

TEST_F(UtenteSuite, TestRimuoviLista) {
    utente.rimuoviLista("Casa");

    ASSERT_EQ(utente.getListe().size(), 1);
}