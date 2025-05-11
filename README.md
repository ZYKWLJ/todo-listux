# 〇、安装说明
### 软件资源：<br>
>**百度网盘：**
<br>通过网盘分享的文件：tl
链接: https://pan.baidu.com/s/119hfiw905vM6FYPFFoBNuA?pwd=todo 提取码: todo 
--来自百度网盘超级会员v6的分享

![网盘里面的资源](https://files.mdnice.com/user/100072/7f02383f-3016-43d4-8c10-fa1c4d0c3aab.png)

>**github:**
<br>
https://github.com/ZYKWLJ/todo-listux/releases/tag/V1.0

会进入这个页面：
![](https://files.mdnice.com/user/100072/17679d84-c29d-450e-bb27-c3903b481c2f.png)
直接下载tl.exe即可！


### 安装过程：
><font size=8>本质</font>：**将tl.exe文件设置进环境变量。**

#### 方式1：
上面下载好的资源里有名为set_tl_to_path.bat的脚本，以**管理员的身份**运行它，输入下载好的tl.exe所在路径，显示成功后，打开cmd，键入tl即可使用软件。


![复制tl.exe所在路径](https://files.mdnice.com/user/100072/a6213577-4409-4b3b-9eee-73bd1f3e3591.png)

![管理员身份运行脚本](https://files.mdnice.com/user/100072/11f923a3-ecc4-407a-8576-601142460663.png)

![运行成功样式](https://files.mdnice.com/user/100072/7d6aae42-7e44-4595-9981-43a92b3ba627.png)

#### 方式2：

手动将tl.exe所在**目录**路径(不是文件!)复制进**系统环境变量**之中，记住，一定要保证是**名为tl.exe**的文件！如果不是，改名为tl.exe再操作。

---
推荐使用方式1，自动化部署，极端情况下，方式1失效的话，再使用方式2。在方式2中，如果您不会设置系统环境变量，请参考如下文章或者我录制的视频：
文章：
https://blog.csdn.net/palmer_kai/article/details/80588594

视频：
https://www.bilibili.com/video/BV1LBETzLEDL?vd_source=9e5ae99f9a8c68dacf39c2666928fc81

**如果还不行，请您联系WeChat：2126483838。备注来意。**

# 一、软件使用说明

## 1.指令格式
**<font size=4><center>tl [command] [arguments]</center></font>**

指令格式说明：
- 每个指令的$Token$ 之间至少有一个**空格间隔**。
- `tl` 属于固参指令，`[command] [arguments]` 属于变参指令。

## 2.指令原语
这就是指令格式中command的可取值。

| ？ | $ | \ | + | - | / |! | = | =\% | \%= |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| help | setting | show | add | done | delete | toggle | replace | prepend | append |

## 3.指令手册

| 程序名 | 指令 | 参数1 | 参数2 | 参数3 | 参数4 | 指令解释 |
| --- | --- | --- | --- | --- | --- | --- |
| tl |? | command |  |  |  | Show command help information |
| tl | $ | key=value |  |  |  | Set configuration key to value |
| tl | \ |  |  |  |  | Show task (today) |
| tl | \ | dt |  |  |  | Show task (current date) |
| tl | \ | dt | df |  |  | Show task (specific date) |
| tl | + | content |  |  |  | Add task (today) |
| tl | + | content | dt |  |  | Add task (current date) |
| tl | + | content | dt | df |  | Add task (specific date) |
| tl | - | tid |  |  |  | Mark task as done (today) |
| tl | - | tid | dt |  |  | Mark task as done (current date) |
| tl | - | tid | dt | df |  | Mark task as done (specific date) |
| tl | / | tid |  |  |  | Delete task (today) |
| tl | / | tid | dt |  |  | Delete task (current date) |
| tl | / | tid | dt | df |  | Delete task (specific date) |
| tl |! | tid |  |  |  | Toggle task (today) |
| tl |! | tid | dt |  |  | Toggle task (current date) |
| tl |! | tid | dt | df |  | Toggle task (specific date) |
| tl | = | tid | content |  |  | Replace task (today) |
| tl | = | tid | content | dt |  | Replace task (current date) |
| tl | = | tid | content | dt | df | Replace task (specific date) |
| tl | =\% | tid | content |  |  | Prepend to task (today) |
| tl | =\% | tid | content | dt |  | Prepend to task (current date) |
| tl | =\% | tid | content | dt | df | Prepend to task (specific date) |
| tl | \%= | tid | content |  |  | Append to task (today) |
| tl | \%= | tid | content | dt |  | Append to task (current date) |
| tl | \%= | tid | content | dt | df | Append to task (specific date) |

注意：

dt可取值

| -d | -w | -m | -y |
| --- | --- | --- | --- |
| 天 | 周 | 月 | 年 |

df可取值

| yyyy.mm.dd | yyyy.mm.ww | yyyy.mm | yyyy |
| --- | --- | --- | --- |
| 年月日 | 年月周 | 年月 | 年 |

# 二、指令大全

## tl? command
帮助命令。

| 指令 | 说明 |
| --- | --- |
| tl? | 显示帮助指令的使用手册 |
| tl? \$ | 显示设置指令的使用手册 |
| tl? \ | 显示查看指令的使用手册 |
| tl? + | 显示添加任务指令的使用手册 |
| tl? - | 显示完成任务指令的使用手册 |
| tl? / | 显示删除任务指令的使用手册 |
| tl?! | 显示切换指令的使用手册 |
| tl? = | 显示替换指令的使用手册 |
| tl? =\% | 显示追加内容指令的使用手册 |
| tl? \%= | 显示前置内容指令的使用手册 |

## tl $ k=v
设置命令。
| 指令 | 说明 |
| --- | --- |
| tl $ color=on | 启用彩色显示 |
| tl $ color=off | 禁用彩色显示 |
| tl $ time=on | 显示时间信息 |
| tl $ time=off | 隐藏时间信息 |
| tl $ border=on | 启用边框显示 |
| tl $ border=off | 禁用边框显示 |

## tl \ dt df
查询命令。
| 指令格式 | 说明 |
| --- | --- |
| tl \ | 显示今日任务 |
| tl \ -d | 显示当前日期任务 |
| tl \ -d 2025.06.01 | 显示2025年6月1日任务 |
| tl \ -w | 显示本周任务 |
| tl \ -w 2025.06.01 | 显示2025年6月第1周任务 |
| tl \ -m | 显示本月任务 |
| tl \ -m 2025.06 | 显示2025年6月任务 |
| tl \ -y | 显示本年任务 |
| tl \ -y 2025 | 显示2025年任务 |

## tl + content dt df
添加命令。
| 指令格式 | 说明 |
| --- | --- |
| tl + content | 添加今日任务 |
| tl + content -d | 添加当前日期任务 |
| tl + content -d 2025.06.01 | 添加2025年6月1日任务 |
| tl + content -w | 添加本周任务 |
| tl + content -w 2025.06.01 | 添加2025年6月第1周任务 |
| tl + content -m | 添加本月任务 |
| tl + content -m 2025.06 | 添加2025年6月任务 |
| tl + content -y | 添加本年任务 |
| tl + content -y 2025 | 添加2025年任务 |

## tl - tid dt df
完成命令。

| 指令格式 | 说明 |
| --- | --- |
| tl - tid | 标记今日任务列表中id为tid的任务为已完成 |
| tl - tid -d | 标记当前日期任务列表中id为tid的任务为已完成 |
| tl - tid -d 2025.06.01 | 标记2025年6月1日任务列表中id为tid的任务为已完成 |
| tl - tid -w | 标记本周任务列表中id为tid的任务为已完成 |
| tl - tid -w 2025.06.01 | 标记2025年6月第1周任务列表中id为tid的任务为已完成 |
| tl - tid -m | 标记本月任务列表中id为tid的任务为已完成 |
| tl - tid -m 2025.06 | 标记2025年6月任务列表中id为tid的任务为已完成 |
| tl - tid -y | 标记本年任务列表中id为tid的任务为已完成 |
| tl - tid -y 2025 | 标记2025年任务列表中id为tid的任务为已完成 |

## tl / tid dt df
删除命令。
| 指令格式 | 说明 |
| --- | --- |
| tl / tid | 删除今日任务列表中id为tid的任务 |
| tl / tid -d | 删除当前日期任务列表中id为tid的任务 |
| tl / tid -d 2025.06.01 | 删除2025年6月1日任务列表中id为tid的任务 |
| tl / tid -w | 删除本周任务列表中id为tid的任务 |
| tl / tid -w 2025.06.01 | 删除2025年6月第1周任务列表中id为tid的任务 |
| tl / tid -m | 删除本月任务列表中id为tid的任务 |
| tl / tid -m 2025.06 | 删除2025年6月任务列表中id为tid的任务 |
| tl / tid -y | 删除本年任务列表中id为tid的任务 |
| tl / tid -y 2025 | 删除2025年任务列表中id为tid的任务 |

## tl! tid dt df
反转命令。
| 指令格式 | 说明 |
| --- | --- |
| tl! tid | 切换今日任务列表中id为tid的任务状态（完成/未完成） |
| tl! tid -d | 切换当前日期任务列表中id为tid的任务状态 |
| tl! tid -d 2025.06.01 | 切换2025年6月1日任务列表中id为tid的任务状态 |
| tl! tid -w | 切换本周任务列表中id为tid的任务状态 |
| tl! tid -w 2025.06.01 | 切换2025年6月第1周任务列表中id为tid的任务状态 |
| tl! tid -m | 切换本月任务列表中id为tid的任务状态 |
| tl! tid -m 2025.06 | 切换2025年6月任务列表中id为tid的任务状态 |
| tl! tid -y | 切换本年任务列表中id为tid的任务状态 |
| tl! tid -y 2025 | 切换2025年任务列表中id为tid的任务状态 |

## tl = tid content dt df
替换命令。
| 指令格式 | 说明 |
| --- | --- |
| tl = tid content | 替换今日任务列表中id为tid的任务内容 |
| tl = tid content -d | 替换当前日期任务列表中id为tid的任务内容 |
| tl = tid content -d 2025.06.01 | 替换2025年6月1日任务列表中id为tid的任务内容 |
| tl = tid content -w | 替换本周任务列表中id为tid的任务内容 |
| tl = tid content -w 2025.06.01 | 替换2025年6月第1周任务列表中id为tid的任务内容 |
| tl = tid content -m | 替换本月任务列表中id为tid的任务内容 |
| tl = tid content -m 2025.06 | 替换2025年6月任务列表中id为tid的任务内容 |
| tl = tid content -y | 替换本年任务列表中id为tid的任务内容 |
| tl = tid content -y 2025 | 替换2025年任务列表中id为tid的任务内容 |

## tl = % tid content dt df
前缀增加命令。
| 指令格式 | 说明 |
| --- | --- |
| tl =\% tid content | 在今日任务列表中id为tid的内容前追加新内容 |
| tl =\% tid content -d | 在当前日期任务列表中id为tid的内容前追加新内容 |
| tl =\% tid content -d 2025.06.01 | 在2025年6月1日任务列表中id为tid的内容前追加新内容 |
| tl =\% tid content -w | 在本周任务列表中id为tid的内容前追加新内容 |
| tl =\% tid content -w 2025.06.01 | 在2025年6月第1周任务列表中id为tid的内容前追加新内容 |
| tl =\% tid content -m | 在本月任务列表中id为tid的内容前追加新内容 |
| tl =\% tid content -m 2025.06 | 在2025年6月任务列表中id为tid的内容前追加新内容 |
| tl =\% tid content -y | 在本年任务列表中id为tid的内容前追加新内容 |
| tl =\% tid content -y 2025 | 在2025年任务列表中id为tid的内容前追加新内容 |

## tl %= tid content dt df
后缀增加命令。
| 指令格式 | 说明 |
| --- | --- |
| tl \%= tid content | 在今日任务列表中id为tid的内容后追加新内容 |
| tl \%= tid content -d | 在当前日期任务列表中id为tid的内容后追加新内容 |
| tl \%= tid content -d 2025.06.01 | 在2025年6月1日任务列表中id为tid的内容后追加新内容 |
| tl \%= tid content -w | 在本周任务列表中id为tid的内容后追加新内容 |
| tl \%= tid content -w 2025.06.01 | 在2025年6月第1周任务列表中id为tid的内容后追加新内容 |
| tl \%= tid content -m | 在本月任务列表中id为tid的内容后追加新内容 |
| tl \%= tid content -m 2025.06 | 在2025年6月任务列表中id为tid的内容后追加新内容 |
| tl \%= tid content -y | 在本年任务列表中id为tid的内容后追加新内容 |
| tl \%= tid content -y 2025 | 在2025年任务列表中id为tid的内容后追加新内容 |


# 三、逐条命令演示

# 逐条命令演示

## tl
![主页](https://files.mdnice.com/user/100072/fa3946a5-0a4e-4f8b-9323-1093bd70e08b.png)

## tl  ?  command
显示命令command的使用手册。
其中command属于下列命令原语之一：
|  ?  |  $  |  \  |  +  |  -  |  /  |  !  |  =  |  =\%  |  \%=  |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |

本小节举几个典例即可。其余均一致。

### tl  ?
![展示help(?)命令的使用](https://files.mdnice.com/user/100072/b1c97c03-4202-41cd-965c-d242919b0ea5.png)

### tl  ?  ?
同tl  ?，不再赘述。

### tl  ?  $
![展示set($)命令的使用](https://files.mdnice.com/user/100072/b2c61747-07b8-44c4-aa88-9ec076614b67.png)
### tl ? +

![展示add(+)命令的使用](https://files.mdnice.com/user/100072/150a8c34-4c5e-46ef-9f10-ef2507afed33.png)

### tl ? /

![展示show(/)命令的使用](https://files.mdnice.com/user/100072/4de70292-911d-4c9d-8cb3-eabefa428ec0.png)

### tl ? -

![展示done(-)命令的使用](https://files.mdnice.com/user/100072/88e6f308-4ed1-4f2d-8700-66f5fa3520c5.png)

### tl ? !
![展示toggle(!)命令的使用](https://files.mdnice.com/user/100072/bf64f50d-c691-4e03-be9b-6ffaef079c11.png)

### tl ? /
![展示delete(/)命令的使用](https://files.mdnice.com/user/100072/5b55592f-da4e-46bb-998c-dee00ad6773c.png)

### tl ? =

![展示replace(=)命令的使用](https://files.mdnice.com/user/100072/9d1ceeaf-eb2f-4116-81e5-ae859982cd25.png)

### tl ? =%

![展示prepend(=%)命令的使用](https://files.mdnice.com/user/100072/9d1ceeaf-eb2f-4116-81e5-ae859982cd25.png)

### tl ? %=

![展示append(%=)命令的使用](https://files.mdnice.com/user/100072/434f8cfd-cadf-4920-a9d1-5c69e5367691.png)




## tl  $  k=v
设置命令。
### tl  $  color=on
### tl  $  color=off
![颜色开关设置](https://files.mdnice.com/user/100072/9159d7c8-fed5-4b7f-9c1d-d66513d26ff4.png)


### tl  $  time=on
### tl  $  time=off
![时间开关设置](https://files.mdnice.com/user/100072/5087f830-2610-4b93-9cbd-42357a1aeced.png)



### tl  $  border=on
### tl  $  border=off 
![边框开关设置](https://files.mdnice.com/user/100072/eb8bfaa8-f50c-448c-b402-8c595d8e36eb.png)


## tl  +  content  [dt]  [df]
添加任务到指定日期。

### tl  +  content
添加任务content到当天。
![添加任务content到当天](https://files.mdnice.com/user/100072/77c5b682-194a-4134-b630-9ffc9940100d.png)


### tl  +  content  -d
同tl  +  content


### tl  +  content  -d  2026.10.01 
添加任务content到指定天(2026年10月1日)。

![添加任务content到指定天(2026年10月1日)](https://files.mdnice.com/user/100072/f566ff45-c422-44cf-b4c2-e69d1e3e8178.png)

### tl  +  content  -w
添加任务content到本周。
![添加任务content到本周](https://files.mdnice.com/user/100072/aec0ffbc-4ed0-4bc0-9d09-4b3ca8cedc53.png)


### tl  +  content  -w  2026.05.04
添加任务content到指定周(2025年5月第四周)。
![添加任务content到指定周(2025年5月第四周)](https://files.mdnice.com/user/100072/2f87072b-9186-466a-90a1-bc0399fedceb.png)

### tl  +  content  -m
添加任务content到本月。
![添加任务content到本月](https://files.mdnice.com/user/100072/19983e65-15ac-4c4b-bf3a-b1310ab11968.png)

### tl  +  content  -m  2026.06
添加任务content到指定月(2026年6月)。


![添加任务content到指定月](https://files.mdnice.com/user/100072/6ab214d0-69ed-4aa0-a329-d333755beca2.png)

### tl  +  content  -y
添加任务content到本年。
![添加任务content到本年](https://files.mdnice.com/user/100072/8eb92994-7f91-4dad-8981-22b626124fea.png)


### tl  +  content  -y  2026
添加任务content到指定年(2026年)。
![添加任务content到指定年(2026年)](https://files.mdnice.com/user/100072/c495d5e8-7816-4fb3-ad68-824040283726.png)


## tl  \  [dt]  [df]
查看指定日期的任务。

### tl  \ 
查看当天的任务
![查看当天的任务](https://files.mdnice.com/user/100072/51d06a30-ed81-4917-9bcb-a941f7eff295.png)


### tl  \  -d
同tl  \ 

### tl  \  -d  2026.01.01
![查看指定天的任务(2026年01月01日)](https://files.mdnice.com/user/100072/069b475e-92b0-4aac-9763-3572bc9adff0.png)


### tl  \  -w
![查看本周的任务](https://files.mdnice.com/user/100072/ea66be6e-ef55-4095-9396-f5f7a6b9e1e5.png)


### tl  \  -w  2025.05.04
![查看指定周的任务(2025年5月第四周)](https://files.mdnice.com/user/100072/8d4cd76b-6768-46f1-a61c-957eb543acf6.png)


### tl  \  -m

![查看本月的任务](https://files.mdnice.com/user/100072/40f7fb6f-c89f-4321-be21-8738901d7dd1.png)


### tl  \  -m  2026.06
 
![查看指定月的任务(2026年6月)](https://files.mdnice.com/user/100072/cf079182-84ad-4ec0-b82b-0d3e7b57f72a.png)


### tl  \  -y
![查看本年的任务](https://files.mdnice.com/user/100072/cceeadf3-9507-4403-9106-70c52adc9cb6.png)

### tl  \  -y  2026
![查看指定年的任务(2026年)](https://files.mdnice.com/user/100072/a4f4b09f-3866-4bc1-9cb4-c0c95e9ae78e.png)


## tl  -  tid  [dt]  [df]
将指定任务标记为已完成。

### tl  -  tid
![将今日任务中ID为tid的任务标记为已完成](https://files.mdnice.com/user/100072/11584a76-4e3d-48c4-8b7d-dd9940711d46.png)


### tl  -  tid  -d
同tl  -  tid

### tl  -  tid  -d  2026.10.01
![将指定日(2026年10月1日)任务中ID为tid的任务标记为已完成](https://files.mdnice.com/user/100072/b4032bdd-fc46-4764-b05d-4276756c700b.png)


### tl  -  tid  -w
。 
![将本周任务中ID为tid的任务标记为已完成](https://files.mdnice.com/user/100072/ecac9f72-f3c9-4f76-af57-72df7ae52a40.png)


### tl  -  tid  -w  2026.05.04

![将指定周(2026年5月第4周)任务中ID为tid的任务标记为已完成](https://files.mdnice.com/user/100072/bf6dec7e-a880-4363-81a3-c6a48d7ef213.png)


### tl  -  tid  -m
![将本月任务中ID为tid的任务标记为已完成](https://files.mdnice.com/user/100072/d06e8a7f-132b-4cae-ba6f-8178b32343c5.png)


### tl  -  tid  -m  2026.06
![将指定月(2026年6月)任务中ID为tid的任务标记为已完成](https://files.mdnice.com/user/100072/b5947d3b-1e45-481d-8367-64f0ad29536e.png)


### tl  -  tid  -y
![将本年任务中ID为tid的任务标记为已完成](https://files.mdnice.com/user/100072/c351318c-76c7-43f7-aac7-d5b271b3ee0b.png)


### tl  -  tid  -y  2026
![将指定年(2026年)任务中ID为tid的任务标记为已完成](https://files.mdnice.com/user/100072/b567b319-f19c-487c-8628-91eb4506d56c.png)



## tl  !  tid  [dt]  [df]
切换指定任务的完成状态（完成/未完成）。

### tl  !  tid
![切换今日任务中ID为tid的任务状态](https://files.mdnice.com/user/100072/48c24aa0-b126-4dc3-945e-fb200641620c.png)


### tl  !  tid  -d
同tl  !  tid

### tl  !  tid  -d  2026.10.01
![切换指定日(2026年10月1日)任务中ID为tid的任务状态](https://files.mdnice.com/user/100072/aaa6717d-eee3-4ce2-9000-a49334743bbb.png)

### tl  !  tid  -w
![切换本周任务中ID为tid的任务状态](https://files.mdnice.com/user/100072/251ba872-6c47-48be-808b-fb9ac02323fd.png)


### tl  !  tid  -w  2026.05.04

![切换指定周(2026年5月第4周)任务中ID为tid的任务状态](https://files.mdnice.com/user/100072/36318395-e9dc-4e80-8a2d-ce05f5076474.png)


### tl  !  tid  -m
![切换本月任务中ID为tid的任务状态](https://files.mdnice.com/user/100072/cb9fb66a-a89c-4010-9c97-ebca6bb602cf.png)

### tl  !  tid  -m  2026.06

![切换指定月(2026年6月)任务中ID为tid的任务状态](https://files.mdnice.com/user/100072/3c6643bd-c316-4587-ab12-4d82f5f9da1e.png)

### tl  !  tid  -y
![切换本年任务中ID为tid的任务状态](https://files.mdnice.com/user/100072/4e081fa9-5179-4812-a6b5-b7021421274c.png)

### tl  !  tid  -y  2026

![切换指定年(2026年)任务中ID为tid的任务状态](https://files.mdnice.com/user/100072/4a603cc4-0147-4195-9e71-74d28c2a92bb.png)


## tl  =  tid  content  [dt]  [df]
替换指定任务的内容。

### tl  =  tid  content
![替换ID为tid的任务内容为content](https://files.mdnice.com/user/100072/4fe541f3-9237-4953-b3b2-c01e8f8caee1.png)

### tl  =  tid  content  -d
同tl  =  tid  content

### tl  =  tid  content  -d  2026.10.01
![替换2026年10月1日任务中ID为tid的任务内容为content](https://files.mdnice.com/user/100072/4a628151-e123-4ca1-a734-d143ab87fb4d.png)

### tl  =  tid  content  -w

![替换本周任务中ID为tid的任务内容为content](https://files.mdnice.com/user/100072/d40b3065-b38a-43c4-8990-84f03a71661e.png)

### tl  =  tid  content  -w  2026.05.04
![替换2026年5月第4周任务中ID为tid的任务内容为content](https://files.mdnice.com/user/100072/94402615-b836-43ea-ab2b-ead43583333b.png)

### tl  =  tid  content  -m
![替换本月任务中ID为tid的任务内容为content](https://files.mdnice.com/user/100072/e13070df-fd39-4e3b-8c0a-137d5107563b.png)

### tl  =  tid  content  -m  2026.06
![替换2026年6月任务中ID为tid的任务内容为content](https://files.mdnice.com/user/100072/6281551c-fce7-4219-a29b-fd7c8170158f.png)

### tl  =  tid  content  -y
![替换本年任务中ID为tid的任务内容为content](https://files.mdnice.com/user/100072/f34b92af-fcc4-4323-86c8-e539a0f9243c.png)

### tl  =  tid  content  -y  2025
![替换2025年任务中ID为tid的任务内容为content](https://files.mdnice.com/user/100072/4c710fc4-f4bb-4eab-a86e-114f9096d7ec.png)


# tl prepend

## tl  =\%  tid  content  [dt]  [df]
在指定任务的内容前添加内容。

### tl  =\%  tid  content
![在当天ID为tid的任务内容前添加content](https://files.mdnice.com/user/100072/2ea975ee-b838-49de-b7a5-6dc1d0344b57.png)



### tl  =\%  tid  content  -d
同tl  =\%  tid  content

### tl  =\%  tid  content  -d  2026.06.01
![在2026年10月1日的ID为tid的任务内容前添加content](https://files.mdnice.com/user/100072/8f23e868-184e-4da1-9cce-8702bf052849.png)

### tl  =\%  tid  content  -w
![在本周的ID为tid的任务内容前添加content](https://files.mdnice.com/user/100072/a5ffe303-80a8-4274-824a-7325e554314a.png)

### tl  =\%  tid  content  -w  2026.05.04
![在2026年5月第4周的ID为tid的任务内容前添加content](https://files.mdnice.com/user/100072/00431134-a972-42cf-8efb-9df40b588e4d.png)

### tl  =\%  tid  content  -m
![在本月的ID为tid的任务内容前添加content](https://files.mdnice.com/user/100072/c15cebe9-4056-4117-b2ee-eeb1f03d4951.png)

### tl  =\%  tid  content  -m  2026.06
![在2026年6月的ID为tid的任务内容前添加content](https://files.mdnice.com/user/100072/325909b3-39db-45d3-99df-09d75912a49d.png)

### tl  =\%  tid  content  -y
![在本年的ID为tid的任务内容前添加content](https://files.mdnice.com/user/100072/d96e0b30-7549-4d08-8765-c68f57659233.png)

### tl  =\%  tid  content  -y  2026
![在2026年的ID为tid的任务内容前添加content](https://files.mdnice.com/user/100072/7637abb3-b531-439f-9e78-192b82bd9f96.png)


# tl append

## tl  +=  tid  content  [dt]  [df]
在指定任务的内容后添加内容。

### tl  +=  tid  content
![在ID为tid的任务内容后添加content（不指定日期和其他标志）](https://files.mdnice.com/user/100072/9f545676-174d-4334-8525-36e965d6efca.png)

### tl  +=  tid  content  -d
同tl  +=  tid  content

### tl  +=  tid  content  -d  2026.10.01
![在2026年10月1日的ID为tid的任务内容后添加content](https://files.mdnice.com/user/100072/5e815345-0ec5-4501-a6a6-b65e7be3747b.png)

### tl  +=  tid  content  -w
![在本周的ID为tid的任务内容后添加content](https://files.mdnice.com/user/100072/cdcff635-bfa5-4106-b1ca-d32ad45b33f1.png)

### tl  +=  tid  content  -w  2026.05.04
![在2026年5月第4周的ID为tid的任务内容后添加content](https://files.mdnice.com/user/100072/620f8918-2bb2-443f-b17a-24f9db06d0f4.png)

### tl  +=  tid  content  -m
![在本月的ID为tid的任务内容后添加content](https://files.mdnice.com/user/100072/af813a5c-38f1-4063-accb-59c728dd1f28.png)

### tl  +=  tid  content  -m  2026.06
![在2026年6月的ID为tid的任务内容后添加content](https://files.mdnice.com/user/100072/e9fe09b9-1c16-432a-91ed-441621df752b.png)

### tl  +=  tid  content  -y
![在本年的ID为tid的任务内容后添加content](https://files.mdnice.com/user/100072/2fb782b3-ec70-4714-816a-875389ceb012.png)

### tl  +=  tid  content  -y  2026
![在2026年的ID为tid的任务内容后添加content](https://files.mdnice.com/user/100072/75d2ff8c-e540-4f60-af96-a11f0fd4d232.png)


# tl delete

## tl  /  tid  [dt]  [df]
删除指定的任务。

### tl  /  tid
![删除ID为tid的任务（不指定日期和其他标志）](https://files.mdnice.com/user/100072/145c6e84-89bc-4f33-a0fb-507ae13d6bc2.png)

### tl  /  tid  -d
同tl  /  tid

### tl  /  tid  -d  2026.10.01
![删除2026年10月1日中ID为tid的任务](https://files.mdnice.com/user/100072/90ce8e8b-5249-456e-a46a-db8c7b67bc6c.png)

### tl  /  tid  -w
![删除本周中ID为tid的任务](https://files.mdnice.com/user/100072/064a240e-f08f-4fac-9800-75956b331149.png)

### tl  /  tid  -w  2026.05.04
![删除2026年5月第4周中ID为tid的任务](https://files.mdnice.com/user/100072/7ec02ac9-ac1a-4336-b07b-fc0e7b666c65.png)

### tl  /  tid  -m
![删除本月中ID为tid的任务](https://files.mdnice.com/user/100072/051f94c1-ae3d-43cf-bf73-7ade0a988eb3.png)

### tl  /  tid  -m  2026.06
![删除2026年6月中ID为tid的任务](https://files.mdnice.com/user/100072/e3522a3b-c74d-43b9-a593-96629a4355fb.png)

### tl  /  tid  -y
![删除本年中ID为tid的任务](https://files.mdnice.com/user/100072/1d36f8e7-a957-41ee-b599-2edd0bf57dc3.png)


### tl  /  tid  -y  2026
![删除2026年中ID为tid的任务](https://files.mdnice.com/user/100072/1929c82d-c25a-4043-9d73-7192344ed73d.png)


# 四、未来展望
(1)任务延顺。今天没完成的任务，可以选择顺延到下一天。

(2)接入网络。本系统为单机系统，未来可接入服务器，云端保存数据。

(3)分布式架构。目前仅仅实现电脑端，后续可实现移动端，提供分布式架构支持。

---
<font size=4><center>**希望这款软件能给您的生活带来一些开心！**</center><font>
