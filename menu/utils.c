void change_color_select(int realPosition, int selectPosition)
{
    if (realPosition == selectPosition)
    {
        change_color(112);
    }
}

int handle_keyboard(int position, int maxPosition)
{
    switch (getch())
    {
    case ARROW_DOWN:
    case KEY_S:
        if (position < maxPosition)
        {
            return position + 1;
        }
        return position;

    case ARROW_UP:
    case KEY_W:
        if (position > 1)
        {
            return position - 1;
        }
        return position;

    case SPACE:
    case ENTER:
        return ENTER_PRESSED;

    case BACKSPACE:
        return BACKSPACE_PRESSED;

    case ESC:
        exit(0);

    default:
        return position;
    }
}