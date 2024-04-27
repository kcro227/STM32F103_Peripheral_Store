# 介绍
该项目是STM32F103使用HAL库对UART1配置DMA IDEL中断接受的例程

# 配置
> - 1.创建工程，使用STM32cubeMX新建工程，配置串口1为异步串口模式，开启接受DMA，生成代码
> - 2.在项目代码的usart.c中定义接收缓存，在main函数中加入如下代码：
>   ```
>     __HAL_UART_ENABLE_IT(&huart1, UART_IT_IDLE);//开启IDEL中断
>     HAL_UART_Receive_DMA(&huart1, rece_BUFF, RECE_BUFF_MAX);//使能接受
>   ```
> - 3.在stm32f1xx_it.c中的USART1_IRQHandler中加入如下代码：
>   ```
>   if(__HAL_UART_GET_FLAG(&huart1,UART_FLAG_IDLE))//判断是否为IDEL中断
>   {
>   __HAL_UART_CLEAR_IDLEFLAG(&huart1);//清除中断标志
>   HAL_UART_DMAStop(&huart1);//停止DMA传输
>   uint8_t Data_Length = RECE_BUFF_MAX - __HAL_DMA_GET_COUNTER(&hdma_usart1_rx);//获取已传输数据数量
>
>   HAL_UART_Transmit(&huart1,rece_BUFF,Data_Length,200);//数据回传
>
>    memset(rece_BUFF,0,Data_Length);//清空接收缓存
>
>    HAL_UART_Receive_DMA(&huart1, rece_BUFF, RECE_BUFF_MAX);//使能接受
>
>
>   }
>   ```

至此，配置结束
