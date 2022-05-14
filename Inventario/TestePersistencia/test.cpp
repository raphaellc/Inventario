#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Inventario/ItemDao.h"
#include "../Inventario/Item.h"
#include "../Inventario/Item.cpp"
#include "../Inventario/Inventario.h"
#include "../Inventario/Inventario.cpp"
#include "../Inventario/ItemDaoBin.h"
#include "../Inventario/ItemDaoBin.cpp"
#include "../Inventario/ItemDaoSeq.h"
#include "../Inventario/ItemDaoSeq.cpp"
//#include "../packages/gmock.1.10.0/lib/native/src/gmock/src/gmock-cardinalities.cc"
using ::testing::Return;
using ::testing::Ne;


class MockItemDao : public ItemDao {
	/*virtual Item* obtemTodosItens() = 0;
	virtual bool guardaTodosItens(Item* it_itens) = 0;*/
public:
	MOCK_METHOD(Item*, obtemTodosItens, (), (override));
	MOCK_METHOD(bool, guardaTodosItens, (Item* it_itens), (override));
};

TEST(TesteComUmItemEComItemDao, testeSalvaInventarioRetornoTrue) {
	//Configura Dados
	MockItemDao mid;
	Item* it = new Item();
	it->id = 1;
	it->peso = 10;
	Inventario * inv = new Inventario();
	inv->defineItemDao(&mid);
	inv->adicionaItem(it);
	
	//Configura expectativa
	EXPECT_CALL(mid, guardaTodosItens(::testing::NotNull())).Times(::testing::AtLeast(1)).WillRepeatedly(Return(true));
	
	//Exercita a expectativa;
	inv->salvaInventario();
	
	ASSERT_EQ(inv->obtemEstado(), true);
	ASSERT_EQ(inv->obtemQuantidadeItens(), 1);
};
TEST(TesteSalvaInventarioSemIDaoSemItem, TesteRetornoFalso) {
	//Arrange
	MockItemDao mid;
	Inventario* inv = new Inventario();
	//Configura Expectativa
	EXPECT_CALL(mid, guardaTodosItens(::testing::NotNull())).Times(0);
	//Act
	bool salva = inv->salvaInventario();
	//Assert
	ASSERT_FALSE(salva);
}

TEST(TesteSalvaInventario, testeGaurdaTodosItensRetornoFalso) {
	//Arrange
	MockItemDao mid;
	Inventario * inv = new Inventario(&mid);
	Item* it = new Item();
	it->id = 1;
	it->peso = 10;
	inv->adicionaItem(it);
	EXPECT_CALL(mid, guardaTodosItens(Ne(nullptr)))
		.Times(::testing::AtLeast(1))
		.WillOnce(Return(false));
	inv->salvaInventario();
	EXPECT_EQ(false, inv->obtemEstado());
	//ASSERT_EQ(inv->obtemQuantidadeItens(), 0);
};
TEST(InstanciarInventario, ObtemItensArmazenados) {
	//Arrange
	MockItemDao mid;
	int qtdItens = 0;
	
	//Configura Expectativa
	EXPECT_CALL(mid, obtemTodosItens()).Times(::testing::AtLeast(1));
	//Act
	Inventario* inv = new Inventario(&mid);
	//Assert
	ASSERT_EQ(qtdItens, inv->obtemQuantidadeItens());
}