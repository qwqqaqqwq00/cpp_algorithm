'''
Description: 
version: 
Author: Rundong Wang
Date: 2023-02-17 09:11:41
LastEditors: Please set LastEditors
LastEditTime: 2023-02-17 10:28:14
'''
from numpy import array
# from sklearn import preprocessing
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
def normalization(data,method,feature_range=(0,1)):
    if(method=='z_score'):
        train_data_scale = data.apply(lambda x: (x - np.mean(x)) / np.std(x) )
    
    if(method=='min_max'):
        train_data_scale = data.apply(lambda x: (x - np.min(x)) / (np.max(x) - np.min(x)))
    return train_data_scale

def radar_map(data,sel_col,player,scale_method,label_num,close_label):
    # x_scale = normalization(data[sel_col],method = scale_method)
    # r1 = pd.Series(data.label).value_counts()
    # r2 = x_scale.groupby(data.label).mean()  #指标统计方法：均值
    # r = pd.concat([r1,r2], axis = 1)     #得到标签各类别的规模
    # r.columns = [label_num] + list(x_scale.columns)  #重命名表头
    
    # result = r.sort_values(label_num,ascending=False)
    # labels = list(result.columns[1:])
    # kinds = list(result.index)
    labels = sel_col
    
    kinds = player
    
    # 由于在雷达图中，要保证数据闭合，这里就再添加雷达图展示指标首列，并转换数据格式为 np.array
    # result = pd.concat([result, result[[close_label]]], axis=1)
    # centers = np.array(result.iloc[:, 1:])
    centers = data
    centers = np.concatenate((centers, centers[:, 0:1]), axis=1)
    
    # 分割圆周长，并让其闭合
    n = len(labels)
    angle0 = np.linspace(0, 2 * np.pi, n, endpoint=False)
    angle = np.concatenate((angle0, [angle0[0]]))
    
    # 绘图
    fig = plt.figure(figsize=(7,7))
    ax = fig.add_subplot(111, polar=True)    # 参数polar, 以极坐标的形式绘制图形
    #画线
    for i in range(len(kinds)):
        ax.plot(angle, centers[i], linewidth=2, label=kinds[i])
        ax.fill(angle, centers[i], alpha=0.15)  # 填充底色
    labels.append(close_label)
    ax.set_thetagrids(angle * 180 / np.pi, labels)   #添加属性标签
    ax.set_ylim(40,100)                                #设置极轴的区间
    ax.set_theta_zero_location('N')                  #设置极轴方向
    plt.grid(c='gray',linestyle='--',)   #设置网格线样式
    plt.title('different kind',fontsize = 20)
    plt.legend(loc='lower right', bbox_to_anchor=(1.7, 0.0)) # 设置图例的位置，在画布外
    plt.show()

def radar_map2(data,sel_col,scale_method,label_num,close_label):
    x_scale = normalization(data[sel_col],method = scale_method)
    r1 = pd.Series(data.label).value_counts()
    r2 = x_scale.groupby(data.label).mean()  #指标统计方法：均值
    r = pd.concat([r1,r2], axis = 1)     #得到标签各类别的规模
    r.columns = [label_num] + list(x_scale.columns)  #重命名表头
    
    result = r.sort_values(label_num,ascending=False)
    labels = list(result.columns[1:])
    kinds = list(result.index)
    
    # 由于在雷达图中，要保证数据闭合，这里就再添加雷达图展示指标首列，并转换数据格式为 np.array
    result = pd.concat([result, result[[close_label]]], axis=1)
    centers = np.array(result.iloc[:, 1:])
    
    # 分割圆周长，并让其闭合
    n = len(labels)
    angle0 = np.linspace(0, 2 * np.pi, n, endpoint=False)
    angle = np.concatenate((angle0, [angle0[0]]))
    
    # 绘图
    fig = plt.figure(figsize=(7,7))
    ax = fig.add_subplot(111, polar=True)    # 参数polar, 以极坐标的形式绘制图形
    
    # 画若干个多边形
    floor = np.floor(centers.min())     # 大于最小值的最大整数
    ceil = np.ceil(centers.max())       # 小于最大值的最小整数
    for i in np.arange(floor, ceil, 0.1):
        ax.plot(angle, [i] * (n + 1), '--', lw=0.5 , color='black')
        
    #画线
    for i in range(len(kinds)):
        ax.plot(angle, centers[i], linewidth=2, label=kinds[i])
        ax.fill(angle, centers[i], alpha=0.25)  # 填充底色
        
    ax.set_thetagrids(angle * 180 / np.pi, labels)   #添加属性标签  
    ax.set_theta_zero_location('N')        # 设置极坐标的起点（即0°）在正北方向，即相当于坐标轴逆时针旋转90°
    ax.spines['polar'].set_visible(False)  # 不显示极坐标最外圈的圆
    ax.set_yticks([])                      # 不显示坐标间隔
    plt.grid(c='gray',linestyle='--',)   #设置网格线样式
    plt.title('different kind',fontsize = 20)
    plt.legend(loc='lower right', bbox_to_anchor=(1.7, 0.0)) # 设置图例的位置，在画布外
    plt.show()

#要展示的指标
sel_col = ['a','b','c','d','e','f']
player = ['vqa2.0', 'od', 'image-generate', '2d', '3d', 'qa', 'math-solve']
#采用的标准化方法
scale_method = 'min_max'

#指标各类别规模统计的列名称
label_num = '类别数目'

#雷达图闭合处指标（第一个展示指标）
close_label = 'a'

train_data = np.random.randint(size=(7, 6), low=50, high=92)

radar_map(train_data,sel_col,player,scale_method,label_num,close_label)

##绘制雷达图
# radar_map2(train_data,sel_col,scale_method,label_num,close_label)
