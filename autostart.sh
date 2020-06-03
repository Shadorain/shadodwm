killall flameshot
killall picom
killall sxhkd

/home/shadow/dwm/dwmblocks/dwmblocks &

sxhkd -c ~/dwm/sxhkdrc &
picom --experimental-backends &
feh --bg-scale --no-fehbg ~/Pictures/Backgrounds/cherry.jpg &
flameshot &
