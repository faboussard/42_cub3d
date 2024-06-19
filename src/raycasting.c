//#include "cub3d.h"
//
//void	my_pixel_put(t_data *img, int x, int y)
//{
//	char	*dst;
//	int		offset_x;
//	int		offset_y;
//
//	if (x >= 0 && x < WIDTH_DISPLAY && y >= 0 && y < HEIGHT_DISPLAY)
//	{
//		dst = img->my_image.addr + ft_abs(offset_x + offset_y);
//		*(unsigned int *)dst = 0x00FF0000;
//	}
//}
//
//int worldMap[mapWidth][mapHeight]=
//		{
//				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//				{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
//				{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
//		};
//
//void raycasting()
//{
//	double posX = 22, posY = 12;  //x and y start position
//	double dirX = -1, dirY = 0; //initial direction vector
//	double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane
//
//	double time = 0; //time of current frame
//	double oldTime = 0; //time of previous frame
//
//	int x;
//	int w;
//	int	h;
//
//	w = WIDTH_DISPLAY;
//	h = HEIGHT_DISPLAY;
//
//	x = 0;
//	while (x < w)
//	{
//		//calculate ray position and direction
//		double cameraX = 2 * x / (double)(w-1); //x-coordinate in camera space
//		double rayDirX = dirX + planeX * cameraX;
//		double rayDirY = dirY + planeY * cameraX;
//
//		//which box of the map we're in
//		int mapX = (int) posX;
//		int mapY = (int) posY;
//
//		//length of ray from current position to next x or y-side
//		double sideDistX;
//		double sideDistY;
//
//// Longueur du rayon d'un côté X ou Y au prochain côté X ou Y
//		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
//		double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
//		double perpWallDist;
//
//// Direction du pas dans la direction X ou Y (soit +1 soit -1)
//		int stepX;
//		int stepY;
//
//		int hit = 0; // Y a-t-il eu un impact sur un mur ?
//		int side;
//
//
//		//calculate step and initial sideDist
//		if (rayDirX < 0)
//		{
//			stepX = -1;
//			sideDistX = (posX - mapX) * deltaDistX;
//		} else
//		{
//			stepX = 1;
//			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
//		}
//		if (rayDirY < 0)
//		{
//			stepY = -1;
//			sideDistY = (posY - mapY) * deltaDistY;
//		} else
//		{
//			stepY = 1;
//			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
//		}
//
//
//		//perform DDA
//		while (hit == 0)
//		{
//			//jump to next map square, either in x-direction, or in y-direction
//			if (sideDistX < sideDistY)
//			{
//				sideDistX += deltaDistX;
//				mapX += stepX;
//				side = 0;
//			} else
//			{
//				sideDistY += deltaDistY;
//				mapY += stepY;
//				side = 1;
//			}
//			//Check if ray has hit a wall
//			if (worldMap[mapX][mapY] > 0)
//				hit = 1;
//		}
//
//		if (side == 0)
//			perpWallDist = (sideDistX - deltaDistX);
//		else
//			perpWallDist = (sideDistY - deltaDistY);
//
//		//Calculate height of line to draw on screen
//		int lineHeight = (int) (h / perpWallDist);
//
//		//calculate lowest and highest pixel to fill in current stripe
//		int drawStart = -lineHeight / 2 + h / 2;
//		if (drawStart < 0)
//			drawStart = 0;
//		int drawEnd = lineHeight / 2 + h / 2;
//		if (drawEnd >= h)
//			drawEnd = h - 1;
//
//		//draw the pixels of the stripe as a vertical line
//		verLine(x, drawStart, drawEnd, color);
//		x++;
//	}
//}