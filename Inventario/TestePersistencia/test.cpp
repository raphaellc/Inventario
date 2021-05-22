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


TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
class MockItemDao : public ItemDao {
	/*virtual Item* obtemTodosItens() = 0;
	virtual bool guardaTodosItens(Item* it_itens) = 0;*/
public:
	MOCK_METHOD(Item*, obtemTodosItens, (), (override));
	MOCK_METHOD(bool, guardaTodosItens, (Item* it_itens), (override));
};

TEST(TesteSemItemDao, testeGaurdaTodosItensRetornoFalsoSemMock) {
	//Arrange
	MockItemDao mid;
	Item* it = new Item();
	it->id = 1;
	it->peso = 10;
	Inventario * inv = new Inventario();
	inv->defineItemDao(&mid);
	inv->adicionaItem(it);
	EXPECT_CALL(mid, guardaTodosItens(::testing::NotNull())).Times(::testing::Exactly(1)).WillRepeatedly(Return(true));
	EXPECT_TRUE(inv->salvaInventario());
	//ASSERT_EQ(false, inv->salvaInventario());
	ASSERT_EQ(inv->obtemQuantidadeItens(), 1);
	
	
	
};

TEST(TesteFalso, testeGaurdaTodosItensRetornoFalso) {
	//Arrange
	MockItemDao mid;
	Inventario * inv = new Inventario(&mid);
	EXPECT_CALL(mid, guardaTodosItens(Ne(nullptr))).Times(::testing::AtMost(2)).WillRepeatedly(Return(false));
	//EXPECT_EQ(false, inv->salvaInventario());
	EXPECT_EQ(false, inv->salvaInventario());
	EXPECT_EQ(false, inv->salvaInventario());
	ASSERT_EQ(inv->obtemQuantidadeItens(), 0);

	
};