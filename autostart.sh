killall dwmblocks
killall flameshot
killall picom
killall sxhkd

killall dwmblocks; ~/dwm/dwmblocks/dwmblocks &

sxhkd -c ~/dwm/sxhkdrc &
picom --experimental-backends &
# feh --no-fehbg ~/Pictures/Backgrounds/cherry.jpg &
# feh --bg-scale --no-fehbg $HOME/Pictures/Backgrounds/forest.png &
feh --bg-scale --no-fehbg $HOME/Pictures/Backgrounds/tripmon/utopia.png
flameshot &
