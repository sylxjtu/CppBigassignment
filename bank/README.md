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