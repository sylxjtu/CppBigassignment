# 原题描述
> 实验一．银行卡管理。

> 问题描述：

> 用VC++可视化开发平台实现某银行的储蓄卡的管理程序。设：某银行共发出M张储蓄卡，每张储 蓄卡拥有唯一的卡号，每天每张储蓄卡至多支持储蓄卡持有者的N笔“存款” 或“取款” 业务。

> 程序中用数组card[M][N+3]中的每一行存放一张储蓄卡的有关信息，其中；

> card[i][0] 存放第i张卡的卡号；

> card[i][1] 存放第i张卡的余额；

> card[i][2] 存放第i张卡的当日业务实际发生笔数；

> card[i][3]~card[i][N+2]存放第i张卡的当日存取款金额，正值代表存款，负值代表取款。

> 当持卡者输入正确的卡号、存款或取款金额后，程序进行相应的处理；若输入了不正确的数据，程序会提示持卡者重新输入；若输入的卡号为负数时，银行终止当日业务。并将当天每张卡的银行业务存到文件中。

##业务
> 1. 开设账户
2. 申请新卡
3. 挂失
4. 存款
5. 取款
6. 转帐

##流程
> 1. 开户：用户填写纸质申请表，出示身份证原件及相关材料，柜台录入信息并核实填写是否准确，之后后台验证其申请的有效性，有效则用户设置密码，生成个人帐户。
2. 办卡：用户填写纸质申请表，出示有效身份证明（身份证），柜台根据证件号、姓名确定个人帐户，若无个人账户则goto: 1.，写入数据库的申请的表，n个工作日后发卡，用户去柜台激活，这时数据库正式卡中写入该卡，申请表中删掉卡。激活时确定密码。
3. 挂失：网上挂失需密码卡号身份证号，忘了就人工：出示身份证件，卡号（忘了就先查个人帐户吧），核实无误，冻结该卡的取款服务。如果补办新卡，走2.，最后把原卡上的钱转到新的卡上；若还想用旧卡号的话也是2.的程序（注意补办需挂失15天以内）；如果不补办，卡找着了本人来柜台激活，估计找不着的可以把钱转到个人账户的其他卡上。
4. 存款：现金+卡号+密码，数据库里加。
5. 取款：卡号+密码，数据库里减。
6. 转帐：自己（卡号+密码）+对方（卡号+姓名），数据库操作，手续费。
7. 修改密码：网上的需原密码，柜台需身份证件，数据库操作。

##接口
```c++

#include <QtCore>

typedef QString ID_t;

enum UserCertType {
	IDCard,
	UndefinedType
};

enum UserStatus{
	Null,
	LoggedIn,
	NotLoggedIn,
	Applied,
	InvalidInfomation
};

enum Status {
	OperationSuccessful,
	CardIDInvalid,
	UserNotFound,
	PasswordNotMatch,
	CashAmountInvalid,
	BalanceNotEnough,
	CardFrozen,
	TransferAmountRestricted,
	TransferTimesRestricted,
	TargetCardIDInvalid,
	TargetCardAnduserNotMatch,
	ReapplyTimeOut,
	UserIDInvalid,
	UserNotLogIn,
	NoAvaliableNetworkConnection,
	UndefinedError
};

class Card {
	public:
		Card(ID_t cardID);

		//基本操作
		Status save(const QString& password, double amount);
		Status withdraw(const QString& password, double amount);
		Status transfer(const QString& password, const ID_t& targetID, const QString& targetUserName, double amouont);
		Status updatePassword(const QString& newPassword, const ID_t& ID, IDType type = IDCard);

		//挂失相关
		Status activate(const QString& password);
		Status loss(const ID_t& cardID);

		//查询相关
		Status query(const QString& password, double& ret);
		ID_t getCardID();
		Status refresh();
};


class Account{
	public:
		Account();
  
		Status register(const QString& username, const ID_t& userCert, UserCertType userCert, const QString& phone, const QString& address);
		//这两个留一个，我觉得去掉前面一个比较好
		//Status login(QString password, const ID_t& uid);
		Status login(const QString& password, const ID_t& userCert, UserCertType userCert = IDCard);

		Status applyNewCard();
		Status reApply(const ID_t& preCardID);

		Status updatePassword(const QString& newPassword, const ID_t& userCert, UserCertType userCert = IDCard);

		ID_t getuid();
		ID_t getID();
		IDType getType();
		UserStatus getStatus();
		ID_t getCardsCount();
		Card& getCard(const ID_t& index);
};

```

