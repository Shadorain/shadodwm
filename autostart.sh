killall flameshot
killall picom
killall sxhkd
killall dwmblocks

sxhkd -c ~/dwm/sxhkdrc &
picom --experimental-backends &
feh --bg-scale --no-fehbg ~/Pictures/Backgrounds/cherry.jpg &
flameshot &
~/dwm/dwmblocks/dwmblocks &
