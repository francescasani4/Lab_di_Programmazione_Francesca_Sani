//
// Created by Francesca Sani
//

#include "gtest/gtest.h"
#include "../Lista.h"
#include "../Utente.h"

class ListaSuite : public ::testing::Test {
protected:
    void SetUp() override {
        lista.aggiungiArticolo(&pasta);
        lista.aggiungiArticolo(&pesto);
    }

    Lista lista{"Spesa"};
    Articolo pasta{"Pasta", "Cibo", 2};
    Articolo pesto{"Pesto", "Condimento", 1};
};

TEST_F(ListaSuite, TestGetIDlista) {
    ASSERT_EQ(lista.getIDlista(), "Spesa");
}

TEST_F(ListaSuite, TestSetIDlista) {
    lista.setIDlista("Casa");

    ASSERT_EQ(lista.getIDlista(), "Casa");
}

TEST_F(ListaSuite, TestAggiugniArticolo) {
    Articolo formaggio("Formaggio", "Cibo", 1);
    lista.aggiungiArticolo(&formaggio);

    ASSERT_EQ(lista.setNonComprato(), 4); /* controllo quanti articoli devo comprare */

    int size = lista.getListaArt().size();
    ASSERT_EQ(size, 3); /* controllo quante voci ho nella lista */
}

TEST_F(ListaSuite, TestRimuoviArticolo) {
    lista.rimuoviArticolo("Pesto");

    ASSERT_EQ(lista.setNonComprato(), 2);

    int size = lista.getListaArt().size();
    ASSERT_EQ(size, 1);
}

TEST_F(ListaSuite, TestSetComprato) {
    lista.setComprato("Pasta");

    ASSERT_EQ(lista.setNonComprato(), 1);
}

TEST_F(ListaSuite, TestNonComprato) {
    ASSERT_EQ(lista.setNonComprato(), 3);
}

TEST_F(ListaSuite, TestSubject) {
    Utente utente("Francesca");
    lista.subscribe(&utente);

    ASSERT_EQ(lista.getObservers().size(), 1);

    lista.unsubscribe(&utente);
    ASSERT_EQ(lista.getObservers().size(), 0);
}