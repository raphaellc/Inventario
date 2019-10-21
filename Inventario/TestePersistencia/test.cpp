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

TEST(TesteItemDAOMock, testeGaurdaTodosItensRetornoFalso) {
	//Arrange
	MockItemDao mid;
	Inventario * inv = new Inventario(&mid);
	EXPECT_CALL(mid, guardaTodosItens(Ne(nullptr))).Times(1).WillOnce(Return(false));
	EXPECT_EQ(false, inv->salvaInventario());
};
TEST(TesteItemDAOMock_1, testeGaurdaTodosItensRetornoVerdadeiro) {

};