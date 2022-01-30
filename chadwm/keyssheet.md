<div align="center">
	<h1>⌨ Keys Sheet</h1>
</div>

## Windows Keys

| Key             | Do                                   |
| --------------- | ------------------------------------ |
| win + b         | toggle bar                           |
| win + ctrl + w  | toggle show tab mode                 |
| win + j         | switch to the previous window        |
| win + k         | switch to the next window            |
| win + h         | add window width                     |
| win + l         | decrease window width                |
| win + shift + h | add window heigth                    |
| win + shift + l | decrease windw heigth                |
| win + shift + j | move down in the current stack       |
| win + shift + k | move up in the current stack         |
| win + i         | change to the next format layout     |
| win + d         | change to the previuos format layout |

## Overall gaps

| Key            | Do                    |
| -------------- | --------------------- |
| win + ctrl + i | add overall gaps      |
| win + ctrl + d | decrease overall gaps |

## Inner gaps

| Key                    | Do                  |
| ---------------------- | ------------------- |
| win + shift + i        | add inner gaps      |
| win + ctrl + shift + i | deacrese inner gaps |

## Outer gaps

| Key                    | Do           | Value |
| ---------------------- | ------------ | ----- |
| win + ctrl + o         | incrogaps    | +1    |
| win + ctrl + shift + o | incrogaps    | -1    |
| win + ctrl + 6         | incrihgaps   | +1    |
| win + ctrl + shift + 6 | incrihgaps   | -1    |
| win + ctrl + 7         | incrivgaps   | +1    |
| win + ctrl + shift + 7 | incrivgaps   | -1    |
| win + ctrl + 8         | incrohgaps   | +1    |
| win + ctrl + shift + 8 | incrohgaps   | -1    |
| win + ctrl + 9         | incrovgaps   | +1    |
| win + ctrl + shift + 9 | incrovgaps   | -1    |
| win + ctrl + shift + d | default gaps | 0     |

## General Keys

| Key                  | Do                                  |
| -------------------- | ----------------------------------- |
| win + q              | kill window                         |
| win + t              | tile layout                         |
| win + shift + t      | bstack layout                       |
| win + y              | spiral layout                       |
| win + shift + y      | dwindle layout                      |
| win + u              | doubledeck layout                   |
| win + shift + u      | monocle layout                      |
| win + shift + f      | toggle floating layout              |
| tab                  | next layout                         |
| shift + tab          | previus layout                      |
| win + space          | focus window                        |
| win + f              | toggle full screen                  |
| win + comma          | switch to the previous monitor      |
| win + period         | switch to the next monitor          |
| win + shift + comma  | send window to the previous monitor |
| win + shift + period | send window to the next monitor     |
| win + shift + p      | add window border                   |
| win + shift + minus  | decrease window border              |
| win + shift + w      | reset window border                 |
| win + ctrl + q       | quit dwm                            |
| win + ctrl + r       | restart dwm                         |

## Applications

| Key             | Application                                  |
| --------------- | -------------------------------------------- |
| win + m         | launch applications menu                     |
| win + shift + m | launch current windows                       |
| win + shift + e | launch emojis                                |
| win + return    | launch terminal (alacritty)                  |
| win + w         | launch browser (google-chrome-stable)        |
| win + e         | launch file explorer (pcmanfm)               |
| win + c         | launch vscode (code)                         |
| win + shift + d | launch database manager (beekeeper-studio)   |
| win + p         | postman                                      |
| win + r         | redshift                                     |
| win + shift + r | stop redshit                                 |
| win + s         | take screenshot (flameshot)                  |
| win + shift + s | take screenshot with 3 seconds delay (scrot) |

## Hardware

| Key                | Functionality            |
| ------------------ | ------------------------ |
| Audio RaiseVolume  | up 2 percent in volume   |
| Audio Lower Volume | down 2 percent volume    |
| Audio Mute         | mute                     |
| MonBrightnessUp    | up 2 percent brihtness   |
| MonBrightnessDown  | down 2 percent brihtness |

## Button definitions

| click         | event mask | button  | function       | argument   |
| ------------- | ---------- | ------- | -------------- | ---------- |
| ClkLtSymbol   | 0          | Button1 | setlayout      | 0          |
| ClkLtSymbol   | 0          | Button3 | setlayout      | layouts[2] |
| ClkWinTitle   | 0          | Button2 | zoom           | 0          |
| ClkStatusText | 0          | Button2 | spawn          | termcmd    |
| ClkClientWin  | win +      | Button1 | moveorplace    | 0          |
| ClkClientWin  | win +      | Button2 | togglefloating | 0          |
| ClkClientWin  | win +      | Button3 | resizemouse    | 0          |
| ClkClientWin  | ctrl +     | Button1 | dragmfact      | 0          |
| ClkClientWin  | ctrl +     | Button3 | dragcfact      | 0          |
| ClkTagBar     | 0          | Button1 | view           | 0          |
| ClkTagBar     | 0          | Button3 | toggleview     | 0          |
| ClkTagBar     | win +      | Button1 | tag            | 0          |
| ClkTagBar     | win +      | Button3 | toggletag      | 0          |
| ClkTabBar     | 0          | Button1 | focuswin       | 0          |
| ClkTabBar     | 0          | Button1 | focuswin       | 0          |
| ClkTabPrev    | 0          | Button1 | movestack      | -1         |
| ClkTabNext    | 0          | Button1 | movestack      | +1         |
| ClkTabClose   | 0          | Button1 | killclient     | 0          |
