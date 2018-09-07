/*******************************************************************************
* @file    W5500.h
* @author  WIZnet Software Team 
* @version V1.0
* @date    2015-xx-xx
* @brief   W5500�Ĵ�����ַ����/�궨���
* @attention
********************************************************************************/
#ifndef  __W5500_H_
#define  __W5500_H_

#include "stm32f10x.h"
#include "types.h"

/**************************************** ͨ�üĴ��� ****************************************/
#define 	MR                          (0x000000)	//ģʽ�Ĵ���

#define 	GAR0                        (0x000100)	//����IP��ַ�Ĵ���
#define 	GAR1                        (0x000200)
#define 	GAR2                        (0x000300)
#define 	GAR3                        (0x000400)

#define 	SUBR0                       (0x000500)	//��������Ĵ���
#define 	SUBR1                       (0x000600)
#define 	SUBR2                       (0x000700)
#define 	SUBR3                       (0x000800)

#define 	SHAR0                       (0x000900)	//ԴMAC��ַ�Ĵ���
#define 	SHAR1                       (0x000A00)
#define 	SHAR2                       (0x000B00)
#define 	SHAR3                       (0x000C00)
#define 	SHAR4                       (0x000D00)
#define 	SHAR5                       (0x000E00)

#define 	SIPR0                       (0x000F00)	//ԴIP��ַ�Ĵ���
#define 	SIPR1                       (0x001000)
#define 	SIPR2                       (0x001100)
#define 	SIPR3                       (0x001200)

#define 	INTLEVEL0                   (0x001300)	//�͵�ƽ�ж϶�ʱ���Ĵ���
#define 	INTLEVEL1                   (0x001400)

/**@brief Interrupt Register*/
#define 	IR                          (0x001500)
/**@brief Interrupt mask register*/
#define 	IMR                         (0x001600)
/**@brief Socket Interrupt Register*/
#define 	SIR							(0x001700) 
/**@brief Socket Interrupt Mask Register*/
#define 	SIMR                        (0x001800)
/**@brief Timeout register address( 1 is 100us )*/
#define 	RTR0                        (0x001900)
#define 	RTR1                        (0x001A00)
/**@brief Retry count reigster*/
#define 	WIZ_RCR						(0x001B00)
/**@briefPPP LCP Request Timer register  in PPPoE mode*/
#define 	PTIMER                      (0x001C00)
/**@brief PPP LCP Magic number register  in PPPoE mode*/
#define 	PMAGIC                      (0x001D00)
/**@brief PPP Destination MAC Register address*/
#define 	PDHAR0                      (0x001E00)
#define 	PDHAR1                      (0x001F00)
#define 	PDHAR2                      (0x002000)
#define 	PDHAR3                      (0x002100)
#define 	PDHAR4                      (0x002200)
#define 	PDHAR5                      (0x002300)
/**
 @brief PPP Session Identification Register
 */
#define 	PSID0                       (0x002400)
#define 	PSID1                       (0x002500)
/**@brief PPP Maximum Segment Size(MSS) register*/
#define 	PMR0                        (0x002600)
#define 	PMR1                        (0x002700)
/**@brief Unreachable IP register address in UDP mode*/
#define 	UIPR0                       (0x002800)
#define 	UIPR1                       (0x002900)
#define 	UIPR2                       (0x002A00)
#define 	UIPR3                       (0x002B00)
/**@brief Unreachable Port register address in UDP mode*/
#define 	UPORT0                      (0x002C00)
#define 	UPORT1                      (0x002D00)
/**@brief PHY Configuration Register*/
#define 	PHYCFGR						(0x002E00)
/**@brief chip version register address*/
#define 	VERSIONR					(0x003900)   
/***********************************************************************************************/

/************************************** Socket�˿ڼĴ��� **************************************/
#define 		Sn_MR(ch)				(0x000008 + (ch<<5))	//Socketģʽ�Ĵ���

#define 		Sn_CR(ch)               (0x000108 + (ch<<5))	//Socket���üĴ���

#define 		Sn_IR(ch)               (0x000208 + (ch<<5))	//Socket�жϼĴ���

#define 		Sn_SR(ch)               (0x000308 + (ch<<5))	//Socket״̬�Ĵ���

#define 		Sn_PORT0(ch)            (0x000408 + (ch<<5))	//Socket n Դ�˿ڼĴ���
#define 		Sn_PORT1(ch)            (0x000508 + (ch<<5))

#define 		Sn_DHAR0(ch)            (0x000608 + (ch<<5))	//Socket n Ŀ�� MAC ��ַ�Ĵ���
#define 		Sn_DHAR1(ch)            (0x000708 + (ch<<5))
#define 		Sn_DHAR2(ch)            (0x000808 + (ch<<5))
#define 		Sn_DHAR3(ch)            (0x000908 + (ch<<5))
#define 		Sn_DHAR4(ch)            (0x000A08 + (ch<<5))
#define 		Sn_DHAR5(ch)            (0x000B08 + (ch<<5))

#define 		Sn_DIPR0(ch)            (0x000C08 + (ch<<5))	//Socket Ŀ�� IP ��ַ�Ĵ���
#define 		Sn_DIPR1(ch)            (0x000D08 + (ch<<5))
#define 		Sn_DIPR2(ch)            (0x000E08 + (ch<<5))
#define 		Sn_DIPR3(ch)            (0x000F08 + (ch<<5))

#define 		Sn_DPORT0(ch)           (0x001008 + (ch<<5))	//Socket n Ŀ��˿ڼĴ���
#define 		Sn_DPORT1(ch)           (0x001108 + (ch<<5))

#define 		Sn_MSSR0(ch)            (0x001208 + (ch<<5))	//Socket n-th ���ֶμĴ���
#define 		Sn_MSSR1(ch)            (0x001308 + (ch<<5))

#define 		Sn_PROTO(ch)            (0x001408 + (ch<<5))	//

#define 		Sn_TOS(ch)              (0x001508 + (ch<<5))	//Socket IP �������ͼĴ���

#define 		Sn_TTL(ch)              (0x001608 + (ch<<5))	//Socket IP ����ʱ��Ĵ���

#define 		Sn_RXMEM_SIZE(ch)       (0x001E08 + (ch<<5))	//Socket n ���ջ����С�Ĵ���

#define 		Sn_TXMEM_SIZE(ch)       (0x001F08 + (ch<<5))	//Socket n ���ͻ����С�Ĵ���

#define 		Sn_TX_FSR0(ch)          (0x002008 + (ch<<5))	//Socket n ���з��ͻ���Ĵ���
#define 		Sn_TX_FSR1(ch)          (0x002108 + (ch<<5))

#define 		Sn_TX_RD0(ch)           (0x002208 + (ch<<5))	//Socket n ���Ͷ�ָ��Ĵ���
#define 		Sn_TX_RD1(ch)           (0x002308 + (ch<<5))

#define 		Sn_TX_WR0(ch)           (0x002408 + (ch<<5))	//Socket n ����дָ��Ĵ���
#define 		Sn_TX_WR1(ch)           (0x002508 + (ch<<5))

#define 		Sn_RX_RSR0(ch)          (0x002608 + (ch<<5))	//Socket n ���н��ջ���Ĵ���
#define 		Sn_RX_RSR1(ch)          (0x002708 + (ch<<5))

#define 		Sn_RX_RD0(ch)           (0x002808 + (ch<<5))	//Socket n ���ն�ָ��Ĵ���
#define 		Sn_RX_RD1(ch)           (0x002908 + (ch<<5))

#define 		Sn_RX_WR0(ch)           (0x002A08 + (ch<<5))	//Socket n ����дָ��Ĵ���
#define 		Sn_RX_WR1(ch)           (0x002B08 + (ch<<5))

#define 		Sn_IMR(ch)				(0x002C08 + (ch<<5))	//Socket n �ж����μĴ���

#define 		Sn_FRAG(ch)				(0x002D08 + (ch<<5))	//Socket n �ֶμĴ���

#define 		Sn_KPALVTR(ch)			(0x002F08 + (ch<<5))	//Socket ����ʱ��Ĵ���


/* MODE register values */
#define MR_RST                       0x80 /**< reset */
#define MR_WOL                       0x20 /**< Wake on Lan */
#define MR_PB                        0x10 /**< ping block */
#define MR_PPPOE                     0x08 /**< enable pppoe */
#define MR_UDP_FARP                  0x02 /**< enbale FORCE ARP */

/* IR register values */
#define IR_CONFLICT                  0x80 /**< check ip confict */
#define IR_UNREACH                   0x40 /**< get the destination unreachable message in UDP sending */
#define IR_PPPoE                     0x20 /**< get the PPPoE close message */
#define IR_MAGIC                     0x10 /**< get the magic packet interrupt */

//Sn_MR values 
#define Sn_MR_CLOSE                  0x00     //0000 0000	--	unused socket
#define Sn_MR_TCP                    0x01     //0000 0001	--	TCP
#define Sn_MR_UDP                    0x02     //0000 0010	--	UDP
#define Sn_MR_IPRAW                  0x03     //0000 0011	--	IP LAYER RAW SOCK
#define Sn_MR_MACRAW                 0x04     //0000 0100	--	MAC LAYER RAW SOCK
#define Sn_MR_PPPOE                  0x05     //0000 0101	--	PPPoE
#define Sn_MR_UCASTB                 0x10     //0001 0000	--	Unicast Block in UDP Multicating
#define Sn_MR_ND                     0x20     //0010 0000	--	No Delayed Ack(TCP) flag
#define Sn_MR_MC                     0x20     //0010 0000	--	Multicast IGMP (UDP) flag
#define Sn_MR_BCASTB                 0x40     //0100 0000	--	Broadcast blcok in UDP Multicating
#define Sn_MR_MULTI                  0x80     //1000 0000	--	support UDP Multicatings

 /* Sn_MR values on MACRAW MODE */
#define Sn_MR_MIP6N                  0x10     /**< IPv6 packet Block */
#define Sn_MR_MMB                    0x20     /**< IPv4 Multicasting Block */
//#define Sn_MR_BCASTB				 0x40     /**< Broadcast blcok */
#define Sn_MR_MFEN                   0x80     /**< support MAC filter enable */

//Sn_CR values 
#define Sn_CR_OPEN                   0x01     //�� Socket n
#define Sn_CR_LISTEN                 0x02     /**< wait connection request in tcp mode(Server mode) */
#define Sn_CR_CONNECT                0x04     /**< send connection request in tcp mode(Client mode) */
#define Sn_CR_DISCON                 0x08     /**< send closing reqeuset in tcp mode */
#define Sn_CR_CLOSE                  0x10     //�ر�Socket n
#define Sn_CR_SEND                   0x20     //����Socket n���ͻ��������еĻ�������
#define Sn_CR_SEND_MAC               0x21     /**< send data with MAC address, so without ARP process */
#define Sn_CR_SEND_KEEP              0x22     /**<  send keep alive message */
#define Sn_CR_RECV                   0x40     //update rxbuf pointer, recv data

#ifdef __DEF_IINCHIP_PPP__
   #define Sn_CR_PCON                0x23      
   #define Sn_CR_PDISCON             0x24      
   #define Sn_CR_PCR                 0x25      
   #define Sn_CR_PCN                 0x26     
   #define Sn_CR_PCJ                 0x27     
#endif

/* Sn_IR values */
#ifdef __DEF_IINCHIP_PPP__
   #define Sn_IR_PRECV               0x80     
   #define Sn_IR_PFAIL               0x40     
   #define Sn_IR_PNEXT               0x20     
#endif

//�ж�����
#define Sn_IR_SEND_OK                0x10     //��SEND�������ʱ����λ��Ч
#define Sn_IR_TIMEOUT                0x08     //��ARP/TCP��ʱ������ʱ����λ��Ч
#define Sn_IR_RECV                   0x04     //���ۺ�ʱ��ֻҪ���յ��˶Է������ݣ���λ��Ч
#define Sn_IR_DISCON                 0x02     //�����յ��Է���FIN or FIN/ACK��ʱ����λ��Ч
#define Sn_IR_CON                    0x01     //���ɹ���Է��������ӣ���Sn_SR��ΪSOCK_ESTABLISHED״̬ʱ����λ��Ч

//Sn_SR values 
#define SOCK_CLOSED                  0x00     //Socket n ���ڹر�״̬����Դ���ͷ�
#define SOCK_INIT                    0x13     //Socket n �˿ڴ򿪲�����TCP����ģʽ
#define SOCK_LISTEN                  0x14     //Socket n ������TCP������ģʽ�£��ҵȴ��Է�����������
#define SOCK_SYNSENT                 0x15     /**< connection state */
#define SOCK_SYNRECV                 0x16     /**< connection state */
#define SOCK_ESTABLISHED             0x17     //Socket n ������״̬
#define SOCK_FIN_WAIT                0x18     /**< closing state */
#define SOCK_CLOSING                 0x1A     /**< closing state */
#define SOCK_TIME_WAIT               0x1B     /**< closing state */
#define SOCK_CLOSE_WAIT              0x1C     //Socket n ���յ����������ӶԷ������ĶϿ���������
#define SOCK_LAST_ACK                0x1D     /**< closing state */
#define SOCK_UDP                     0x22     //Socket n ����UDPģʽ��
#define SOCK_IPRAW                   0x32     /**< ip raw mode socket */
#define SOCK_MACRAW                  0x42     //ָʾSocket 0������MACRAWģʽ�£�MACRAWģʽ����Socket 0����Ч
#define SOCK_PPPOE                   0x5F     /**< pppoe socket */

/* IP PROTOCOL */
#define IPPROTO_IP                   0        /**< Dummy for IP */
#define IPPROTO_ICMP                 1        /**< Control message protocol */
#define IPPROTO_IGMP                 2        /**< Internet group management protocol */
#define IPPROTO_GGP                  3        /**< Gateway^2 (deprecated) */
#define IPPROTO_TCP                  6        /**< TCP */
#define IPPROTO_PUP                  12       /**< PUP */
#define IPPROTO_UDP                  17       /**< UDP */
#define IPPROTO_IDP                  22       /**< XNS idp */
#define IPPROTO_ND                   77       /**< UNOFFICIAL net disk protocol */
#define IPPROTO_RAW                  255      /**< Raw IP packet */

extern uint8 txsize[];
extern uint8 rxsize[];

/*********************************************************
* iinchip access function
*********************************************************/
void iinchip_init(void); // reset iinchip
void socket_buf_init(uint8 * tx_size, uint8 * rx_size); // setting tx/rx buf size
uint8 getISR(uint8 s);
void putISR(uint8 s, uint8 val);
uint16 getIINCHIP_RxMAX(uint8 s);
uint16 getIINCHIP_TxMAX(uint8 s);
void setMR(uint8 val);
void setRTR(uint16 timeout); // set retry duration for data transmission, connection, closing ...
void setRCR(uint8 retry); // set retry count (above the value, assert timeout interrupt)
void clearIR(uint8 mask); // clear interrupt
uint8 getIR( void );
void setSn_MSS(SOCKET s, uint16 Sn_MSSR); // set maximum segment size
uint8 getSn_IR(SOCKET s); // get socket interrupt status
uint8 getSn_SR(SOCKET s); // get socket status
uint16 getSn_TX_FSR(SOCKET s); // get socket TX free buf size
uint16 getSn_RX_RSR(SOCKET s); // get socket RX recv buf size
uint8 getSn_SR(SOCKET s);
void setSn_TTL(SOCKET s, uint8 ttl);
void send_data_processing(SOCKET s, uint8 *wizdata, uint16 len);
void recv_data_processing(SOCKET s, uint8 *wizdata, uint16 len);

void setGAR(uint8 * addr); // set gateway address
void setSUBR(uint8 * addr); // set subnet mask address
void setSHAR(uint8 * addr); // set local MAC address
void setSIPR(uint8 * addr); // set local IP address
void getGAR(uint8 * addr);
void getSUBR(uint8 * addr);
void getSHAR(uint8 * addr);
void getSIPR(uint8 * addr);

void setSn_IR(uint8 s, uint8 val);
void Reset_W5500(void);



/**
 @brief WIZCHIP_OFFSET_INC on IINCHIP_READ/WRITE
 * case1.
 *  IINCHIP_WRITE(RTR0,val);
 *  IINCHIP_WRITE(RTR1,val);
 * case1. 
 *  IINCHIP_WRITE(RTR0,val);
 *  IINCHIP_WRITE(WIZCHIP_OFFSET_INC(RTR0,1)); 
 */
//#define WIZCHIP_OFFSET_INC(ADDR, N)    (ADDR + (N<<8)) //< Increase offset address

#endif
