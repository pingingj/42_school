
// void	change_number_bg(t_mlx *mlx, int moves, t_img *img, int size)
// {
// 	int	x;
// 	int	y;
// 	int	position;

// 	position =  mlx.pos.x * 96 / 2
// 	if(size == 1)
// 		position += 34
// 	if(size == 2)
// 		position -= 18
// 	if(size == 3)
// 		position -= 71
// 	while(x < 38)
// 	{
// 		while(y < 85)
// 		{
// 			color = pixel_get(img, width, height);
// 			my_mlx_pixel_put(&mlx->bg_img, x + width, y + height, color);
// 			y++;
// 		}
// 		x++;
// 	}
// }

void	ft_putnbr(int moves, char **filenames, int *size)
{
	int	result;

	if (moves >= 10)
		ft_putnbr(moves / 10, filenames, size);

	result = moves % 10;
	(*size)++;
	printf("%d and the file name is..... %s and its the %d number\n", result, filenames[result], (*size));
	// change_number_bg(moves, mlx.numbers.images[result], size);
}

int CHANGETHIS(int argc, char **argv)
{
    char    *filenames[10];
    int     moves;
	int		size;
    filenames[0] = "zero.xpm";
    filenames[1] = "one.xpm";
    filenames[2] = "two.xpm";
    filenames[3] = "three.xpm";
    filenames[4] = "four.xpm";
    filenames[5] = "five.xpm";
    filenames[6] = "six.xpm";
    filenames[7] = "seven.xpm";
    filenames[8] = "eight.xpm";
    filenames[9] = "nine.xpm";
    filenames[10] = NULL;
	if (argc != 2)
		return (1);
	size = 0;
    moves = atoi(argv[1]);
	ft_putnbr(moves, filenames, &size);
	printf("\nsize = %d\n", size);
}
