killall flameshot
killall picom
killall sxhkd
killall dzen2

sxhkd -c ~/dwm/sxhkdrc &
picom --experimental-backends &
feh --bg-scale --no-fehbg ~/Pictures/Backgrounds/cherry.jpg &
~/dwm/dwmst/dwmst &
flameshot &
