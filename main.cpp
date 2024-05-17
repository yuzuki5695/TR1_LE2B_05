#include <Novice.h>
#include <Vector2.h>
#define _USE_MATH_DEFINES
#include <math.h>

const char kWindowTitle[] = "LE2B_05_オノデラ_ユヅキ";

/* --- Sine --- */
float EaseInSine(float t) {
	return 1.0f - cosf((t * static_cast<float>(M_PI)) / 2.0f);
}


float EaseOutExpo(float t) {
	return t == 1.0f
		? 1.0f
		: 1.0f - powf(2.0f, -10.0f * t);
}

float EaseInOutQuint(float t) {
	return t < 0.5f
		? 16.0f * t * t * t * t * t
		: 1.0f - powf(-2.0f * t + 2.0f, 5.0f) / 2.0f;
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};


	int fige = 0;
	
	float t[2] = { 0 };
	float t2[2] = { 0 };
	int flag[2] = { 0,0 };


	int tex = Novice::LoadTexture("./NoviceResources/white1x1.png");

	Vector2 start1[4];
	Vector2 start2[4];
	Vector2 start3[4];
	Vector2 start4[4];
	
	Vector2 end[4] = {
		-300.0f,1300.0f,
		600.0f,1300.0f,
		-300.0f,1300.0f,
		600.0f,1300.0f
	};	
	Vector2 move = { 30.0f,30.0f };

	Vector2 QuadPosA[4] = {
	{600.0f, 330.0f },
	{660.0f, 330.0f },
	{600.0f, 350.0f },
	{660.0f, 350.0f }
	};

	Vector2 QuadPosB[4] = {
	{610.0f, 350.0f},
	{650.0f, 350.0f},
	{610.0f, 400.0f},
	{650.0f, 400.0f}
	};

	Vector2 TrianglePos1[4]{
    {110.0f, -150.0f},
	{150.0f, -150.0f},
	{130.0f, -50.0f},
	{130.0f, -50.0f}
	};
	Vector2 TrianglePos2[4]{
	{410.0f , -150.0f},
	{450.0f , -150.0f},
	{430.0f , -50.0f},
	{430.0f , -50.0f}
	};
	Vector2 TrianglePos3[4]{
{710.0f , -150.0f},
{750.0f , -150.0f},
{730.0f ,-50.0f},
{730.0f , -50.0f}
	};
	Vector2 TrianglePos4[4]{
{1010.0f , -150.0f},
{1050.0f , -150.0f},
{1030.0f , -50.0f},
{1030.0f , -50.0f}
	};
	


	for (int i = 0; i < 4; i++) {
		start1[i].x = TrianglePos1[i].x;
		start1[i].y = TrianglePos1[i].y;
		start2[i].x = TrianglePos2[i].x;
		start2[i].y = TrianglePos2[i].y;
		start3[i].x = TrianglePos3[i].x;
		start3[i].y = TrianglePos3[i].y;
		start4[i].x = TrianglePos3[i].x;
		start4[i].y = TrianglePos3[i].y;
		if (i == 0) {
			end[i].x = TrianglePos1[i].x - 610.0f;
			end[i].x = TrianglePos2[i].x - 810.0f;
			end[i].x = TrianglePos3[i].x - 1110.0f;
			end[i].x = TrianglePos4[i].x - 1410.0f;
		} else if (i == 2) {
			end[i].x = TrianglePos1[i].x - 630.0f;
			end[i].x = TrianglePos2[i].x - 830.0f;
			end[i].x = TrianglePos3[i].x - 1130.0f;
			end[i].x = TrianglePos4[i].x - 1430.0f;
		} else {
			end[i].x = TrianglePos1[i].x + 670.0f;
			end[i].x = TrianglePos2[i].x + 870.0f;
			end[i].x = TrianglePos3[i].x + 1170.0f;
			end[i].x = TrianglePos4[i].x + 1470.0f;
		}
	}
	int Easeingflge = 0;
	int sceneflge = 0;
	int inte = 0;

	Vector2 Player = {630.0f,315.0f};
	Vector2 radius = { 15.0f,15.0f };
	float moveY = 0.5f;	
	int Playermove = 0;

	
	Vector2 effect={ 630.0f,345.0f };
	Vector2 effectradius = { 10.0f,10.0f };

	int effectfige = 0;
	int scenefi = 0;
	int time = 0;

	int BlockColor = 0;
	int BlockColorfige = 0;

	Vector2 effect2 = { -200.0f,0.0f };
	Vector2 effectradius2 = { 180.0f,720.0f };
	Vector2 effectstart2 = { -200.0f,50.0f };
	Vector2 effectend2 = { 1280.0f,0.0f };
	int effectfige2 = 0;
	float effect2t = 0.0f;

	Vector2 wall = { -200.0f,0.0f };
	Vector2 wallradius = { 180.0f,720.0f };

	Vector2 ghostplayerX = { 630.0f,315.0f };
	Vector2 ghoststartX = { 630.0f,315.0f };
	Vector2 ghostendX = { 1910.0f,315.0f };
	float ScrollX = 0;
	float ghosttX = 0.0f;
	int ghostplayerfigeX = 0;

	Vector2 ghostplayerY = { 630.0f,315.0f };
	Vector2 ghoststartY = { 630.0f,315.0f };
	Vector2 ghostendY = { 630.0f,1035.0f };
	float ScrollY = 0;
	float ghosttY = 0.0f;
	int ghostplayerfigeY = 0;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();
	
		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		if (inte == 0) {

			fige = 0;

			t[0] = { 0 }; t[1] = { 0 };
			t2[0] = { 0 }; t2[1] = { 0 };
			flag[0] = { 0 };	 flag[1] = { 0 };

			TrianglePos1[0] = { 110.0f, -150.0f };
			TrianglePos1[1] = { 150.0f, -150.0f };
			TrianglePos1[2] = { 130.0f, -50.0f };
			TrianglePos1[3] = { 130.0f, -50.0f };

			TrianglePos2[0] = { 410.0f , -150.0f };
			TrianglePos2[1] = { 450.0f , -150.0f };
			TrianglePos2[2] = { 430.0f , -50.0f };
			TrianglePos2[3] = { 430.0f , -50.0f };

			TrianglePos3[0] = { 710.0f , -150.0f };
			TrianglePos3[1] = { 750.0f , -150.0f };
			TrianglePos3[2] = { 730.0f ,-50.0f };
			TrianglePos3[3] = { 730.0f , -50.0f };

			TrianglePos4[0] = { 1010.0f , -150.0f };
			TrianglePos4[1] = { 1050.0f , -150.0f };
			TrianglePos4[2] = { 1030.0f , -50.0f };
			TrianglePos4[3] = { 1030.0f , -50.0f };



			for (int i = 0; i < 4; i++) {
				start1[i].x = TrianglePos1[i].x;
				start1[i].y = TrianglePos1[i].y;
				start2[i].x = TrianglePos2[i].x;
				start2[i].y = TrianglePos2[i].y;
				start3[i].x = TrianglePos3[i].x;
				start3[i].y = TrianglePos3[i].y;
				start4[i].x = TrianglePos3[i].x;
				start4[i].y = TrianglePos3[i].y;
				if (i == 0) {
					end[i].x = TrianglePos1[i].x - 610.0f;
					end[i].x = TrianglePos2[i].x - 810.0f;
					end[i].x = TrianglePos3[i].x - 1110.0f;
					end[i].x = TrianglePos4[i].x - 1410.0f;
				} else if (i == 2) {
					end[i].x = TrianglePos1[i].x - 630.0f;
					end[i].x = TrianglePos2[i].x - 830.0f;
					end[i].x = TrianglePos3[i].x - 1130.0f;
					end[i].x = TrianglePos4[i].x - 1430.0f;
				} else {
					end[i].x = TrianglePos1[i].x + 670.0f;
					end[i].x = TrianglePos2[i].x + 870.0f;
					end[i].x = TrianglePos3[i].x + 1170.0f;
					end[i].x = TrianglePos4[i].x + 1470.0f;
				}
			}
			Easeingflge = 0;
			sceneflge = 0;
		
		}

		if (scenefi == 0 && t[0] == 1.0f) {
			effect2.x = -200.0f; effect2.y = 0.0f;
			effect2t = 0.0f;
			wall.x = -200.0f; wall.y = 0.0f;
			wallradius.x = 180.0f; wallradius.y = 720.0f;

			ghostplayerX.x = 630.0f; ghostplayerX.y = 315.0f;
			ghosttX = 0.0f;

			ghostplayerY.x = 630.0f; ghostplayerY.y = 315.0f;
			ghosttY = 0.0f;

		};


		
		if (keys[DIK_SPACE] && Easeingflge == 0) {
			for (int i = 0; i < 6; i++) {
				if (i == scenefi) {
					Playermove = 1;
					Easeingflge = 1;
				}
			}	
				inte = 1; 
			
		}

		if (Playermove == 1) {
			Player.y += moveY;
			if (Player.y >= 345.0f) {
				Player.y = 345.0f;
				Playermove = 0;
				if (scenefi == 0) {
					flag[0] = 1;			
				} else if (scenefi == 1) {
					effectfige = 1;
				} else if (scenefi == 2) {
					BlockColorfige = 1;
				} else if (scenefi == 3) {
					effectfige2 = 1;
				} else if (scenefi == 4) {
					ghostplayerfigeX = 1;
				} else if (scenefi == 5) {
					ghostplayerfigeY = 1;
				}
				
			}
		}else if (Playermove == 2) {
			Player.y -= moveY;
			if (Player.y <= 315.0f) {
				Player.y = 315.0f;	
				Playermove = 0;
				if (scenefi == 0) {
					inte = 0;
					scenefi = 1;						
				}else if (effectfige == 2 && scenefi == 1) {
					inte = 0;
					effectfige = 0;
					scenefi = 2;					
				} else if (BlockColorfige == 2 && scenefi == 2) {
					inte = 0;
					time = 0;
					BlockColor = 0;
					BlockColorfige = 0;
					scenefi = 3;
				} else if (effectfige2 == 1 && scenefi == 3) {
					inte = 0;		
					effectfige2 = 0;
					scenefi = 4;
				} else if (ghostplayerfigeX == 1 && scenefi == 4) {
					inte = 0;
					ghostplayerfigeX = 0;
					scenefi = 5;
				} else if (ghostplayerfigeY == 1 && scenefi == 5) {
					inte = 0;
					ghostplayerfigeY = 0;
					scenefi = 0;
				}
			}
		}

			if (Easeingflge == 1) {
				
				if (flag[0] == 1) {
					t[0] += (1.0f / 60.0f);
				}
				if (t[0] > 1.0f) {
					t[0] = 1.0f;
					flag[0] = 0;
				}

				if (flag[0] == 1) {
					TrianglePos1[2].y = (1.0f - EaseOutExpo(t[0])) * start1[2].y + EaseOutExpo(t[0]) * end[2].y;
					TrianglePos1[3].y = (1.0f - EaseOutExpo(t[0])) * start1[3].y + EaseOutExpo(t[0]) * end[3].y;
					TrianglePos2[2].y = (1.0f - EaseOutExpo(t[0])) * start2[2].y + EaseOutExpo(t[0]) * end[2].y;
					TrianglePos2[3].y = (1.0f - EaseOutExpo(t[0])) * start2[3].y + EaseOutExpo(t[0]) * end[3].y;
					TrianglePos3[2].y = (1.0f - EaseOutExpo(t[0])) * start3[2].y + EaseOutExpo(t[0]) * end[2].y;
					TrianglePos3[3].y = (1.0f - EaseOutExpo(t[0])) * start3[3].y + EaseOutExpo(t[0]) * end[3].y;
					TrianglePos4[2].y = (1.0f - EaseOutExpo(t[0])) * start4[2].y + EaseOutExpo(t[0]) * end[2].y;
					TrianglePos4[3].y = (1.0f - EaseOutExpo(t[0])) * start4[3].y + EaseOutExpo(t[0]) * end[3].y;

				}

				if (t[0] >= 0.5f) {
					flag[1] = 1;
				}
				if (flag[1] == 1) {
					t2[0] += (1.0f / 60.0f);
				}

				if (flag[1] == 1) {
					TrianglePos1[0].x = (1.0f - EaseOutExpo(t2[0])) * start1[0].x + EaseOutExpo(t2[0]) * end[0].x;
					TrianglePos1[1].x = (1.0f - EaseOutExpo(t2[0])) * start1[1].x + EaseOutExpo(t2[0]) * end[1].x;
					TrianglePos2[0].x = (1.0f - EaseOutExpo(t2[0])) * start2[0].x + EaseOutExpo(t2[0]) * end[0].x;
					TrianglePos2[1].x = (1.0f - EaseOutExpo(t2[0])) * start2[1].x + EaseOutExpo(t2[0]) * end[1].x;
					TrianglePos3[0].x = (1.0f - EaseOutExpo(t2[0])) * start3[0].x + EaseOutExpo(t2[0]) * end[0].x;
					TrianglePos3[1].x = (1.0f - EaseOutExpo(t2[0])) * start3[1].x + EaseOutExpo(t2[0]) * end[1].x;
					TrianglePos4[0].x = (1.0f - EaseOutExpo(t2[0])) * start4[0].x + EaseOutExpo(t2[0]) * end[0].x;
					TrianglePos4[1].x = (1.0f - EaseOutExpo(t2[0])) * start4[1].x + EaseOutExpo(t2[0]) * end[1].x;
				}

				if (t2[0] > 1.0f) {
					t2[0] = 1.0f;
					flag[1] = 0;
					Easeingflge = 2;
					sceneflge = 1;
				}

			}

			if (Easeingflge == 2) {
				if (sceneflge == 1) {
					flag[1] = 1;
				}

				if (flag[0] == 1) {
					t[0] -= (1.0f / 60.0f);
				}
				if (t[1] > 1.0f) {
					t[1] = 1.0f;
					flag[0] = 0;			
					sceneflge = 0;				
				}

				if (flag[0] == 1) {
					TrianglePos1[2].y = (1.0f - EaseOutExpo(t[0])) * start1[2].y + EaseOutExpo(t[0]) * end[2].y;
					TrianglePos1[3].y = (1.0f - EaseOutExpo(t[0])) * start1[3].y + EaseOutExpo(t[0]) * end[3].y;
					TrianglePos2[2].y = (1.0f - EaseOutExpo(t[0])) * start2[2].y + EaseOutExpo(t[0]) * end[2].y;
					TrianglePos2[3].y = (1.0f - EaseOutExpo(t[0])) * start2[3].y + EaseOutExpo(t[0]) * end[3].y;
					TrianglePos3[2].y = (1.0f - EaseOutExpo(t[0])) * start3[2].y + EaseOutExpo(t[0]) * end[2].y;
					TrianglePos3[3].y = (1.0f - EaseOutExpo(t[0])) * start3[3].y + EaseOutExpo(t[0]) * end[3].y;
					TrianglePos4[2].y = (1.0f - EaseOutExpo(t[0])) * start4[2].y + EaseOutExpo(t[0]) * end[2].y;
					TrianglePos4[3].y = (1.0f - EaseOutExpo(t[0])) * start4[3].y + EaseOutExpo(t[0]) * end[3].y;

				}

				if (t2[0] >= 0.5f) {
					flag[0] = 1;				
				}
				if (flag[1] == 1) {
					t2[0] -= (1.0f / 60.0f);
				}

				if (flag[1] == 1) {
					TrianglePos1[0].x = (1.0f - EaseOutExpo(t2[0])) * start1[0].x + EaseOutExpo(t2[0]) * end[0].x;
					TrianglePos1[1].x = (1.0f - EaseOutExpo(t2[0])) * start1[1].x + EaseOutExpo(t2[0]) * end[1].x;
					TrianglePos2[0].x = (1.0f - EaseOutExpo(t2[0])) * start2[0].x + EaseOutExpo(t2[0]) * end[0].x;
					TrianglePos2[1].x = (1.0f - EaseOutExpo(t2[0])) * start2[1].x + EaseOutExpo(t2[0]) * end[1].x;
					TrianglePos3[0].x = (1.0f - EaseOutExpo(t2[0])) * start3[0].x + EaseOutExpo(t2[0]) * end[0].x;
					TrianglePos3[1].x = (1.0f - EaseOutExpo(t2[0])) * start3[1].x + EaseOutExpo(t2[0]) * end[1].x;
					TrianglePos4[0].x = (1.0f - EaseOutExpo(t2[0])) * start4[0].x + EaseOutExpo(t2[0]) * end[0].x;
					TrianglePos4[1].x = (1.0f - EaseOutExpo(t2[0])) * start4[1].x + EaseOutExpo(t2[0]) * end[1].x;
				}

				if (t2[0] < 0.0f) {
					t2[0] = 0.0f;
					flag[1] = 0;			
					Playermove = 2;
				}


			}

			if (effectfige == 1) {
				if (effectradius.x <= 1500) {
					effectradius.x += 25.0f;
					effectradius.y += 25.0f;
				} else if (effectradius.x >= 1500) {
					effectfige = 2;
				}
			}
			if (effectfige == 2) {
				if (effectradius.x >= 10) {
					effectradius.x -= 25.0f;
					effectradius.y -= 25.0f;
				} else {
					Playermove = 2;
				}
			}

			if (BlockColorfige == 1) {
				if (BlockColor <= 248) {
					BlockColor += 7;
				} else if (BlockColor >= 248) {
					time++;
					if (time >= 50) {
						BlockColorfige = 2;
					}
				}
			}
			if (BlockColorfige == 2) {
				if (BlockColor >= 5) {
					BlockColor -= 5;
				} 	
				if (BlockColor >= 20) {
					Playermove = 2;
				}
			}

			if (effectfige2 == 1) {
				effect2t += (1.0f / 90.0f);		
			}
			wallradius.x = (effect2.x + 200.0f);	
			if (effectfige2 == 1) {
				effect2.x = (1.0f - EaseInOutQuint(effect2t)) * effectstart2.x + EaseInOutQuint(effect2t) * effectend2.x;
			}
			if (effect2t > 1.0f) {
				effect2t = 1.0f;
				Playermove = 2;			
			}		
			
			if (ghostplayerfigeX == 1) {				
				ghosttX += (1.0f / 90.0f);	
			}

			if (ghostplayerfigeX == 1) {
				ghostplayerX.x = (1.0f - EaseInOutQuint(ghosttX)) * ghoststartX.x + EaseInOutQuint(ghosttX) * ghostendX.x;
			}
			if (ghosttX > 1.0f) {
				ghosttX = 1.0f;	
				Playermove = 2;
			}

		
			if (ghostplayerfigeY == 1) {
				ghosttY += (1.0f / 90.0f);
			}

			if (ghostplayerfigeY == 1) {
				ghostplayerY.y = (1.0f - EaseInOutQuint(ghosttY)) * ghoststartY.y + EaseInOutQuint(ghosttY) * ghostendY.y;
			}
			if (ghosttY > 1.0f) {
				ghosttY = 1.0f;		
				Playermove = 2;
			}



			if (ghostplayerX.x >= 630 && ghostplayerX.x <= 1910) {
				ScrollX = ghostplayerX.x - 630.0f;
			}

			if (ghostplayerY.y >= 315 && ghostplayerY.y <= 1035) {
				ScrollY = ghostplayerY.y - 315.0f;
			}



		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

			Novice::DrawBox(
				1280 - (int)ScrollX,0 + (int)ScrollY,
				1280,720,
				0.0f, 0xAAAAAAAA, kFillModeSolid);
			Novice::DrawBox(
				1280 - (int)ScrollX, 0 - 720 + (int)ScrollY,
				1280, 720,
				0.0f, 0xAAAA00CC, kFillModeSolid);

		
		
		Novice::DrawBox(
			int(wall.x - ScrollX), int(wall.y),
			int(wallradius.x), int(wallradius.y),
			0.0f, 0x33AA33AA, kFillModeSolid);
		
		
		
		if (ghosttX == 0.0f || ghosttX == 1.0f) {
			if (scenefi >= 1 && scenefi <= 4) {
				Novice::DrawEllipse(
					int(Player.x), int(Player.y),
					int(radius.x), int(radius.y),
					0.0f,
					RED,
					kFillModeSolid
				);
			}

		}
		if(ghosttY == 0.0f || ghosttY == 1.0f) {
			if (scenefi >= 5 || scenefi == 0) {
				Novice::DrawEllipse(
					int(Player.x), int(Player.y),
					int(radius.x), int(radius.y),
					0.0f,
					RED,
					kFillModeSolid
				);
			}

		}



		Novice::DrawLine(0 - (int)ScrollX, 400 + (int)ScrollY, 1280 - (int)ScrollX, 400 + (int)ScrollY, BLACK);
		Novice::DrawLine(1280 - (int)ScrollX, 400 + (int)ScrollY, 2560 - (int)ScrollX, 400 + (int)ScrollY, WHITE);
		Novice::DrawLine(0 - (int)ScrollX, 400 - 720 + (int)ScrollY, 2560 - (int)ScrollX, 400 - 720 + (int)ScrollY, 0xDD0000FF);
	
		Novice::DrawQuad(
			int(QuadPosA[0].x - ScrollX), int(QuadPosA[0].y+ ScrollY),
			int(QuadPosA[1].x - ScrollX), int(QuadPosA[1].y+ ScrollY),
			int(QuadPosA[2].x - ScrollX), int(QuadPosA[2].y+ ScrollY),
			int(QuadPosA[3].x - ScrollX), int(QuadPosA[3].y+ ScrollY),
			0, 0,
			0, 0,
			tex,
			WHITE
		);

		Novice::DrawQuad(
			int(QuadPosB[0].x - ScrollX), int(QuadPosB[0].y+ ScrollY),
			int(QuadPosB[1].x - ScrollX), int(QuadPosB[1].y+ ScrollY),
			int(QuadPosB[2].x - ScrollX), int(QuadPosB[2].y+ ScrollY),
			int(QuadPosB[3].x - ScrollX), int(QuadPosB[3].y+ ScrollY),
			0, 0,
			0, 0,
			tex,
			WHITE
		);


		Novice::DrawQuad(
			int(QuadPosA[0].x + 1280.0f - ScrollX), int(QuadPosA[0].y + ScrollY),
			int(QuadPosA[1].x + 1280.0f - ScrollX), int(QuadPosA[1].y + ScrollY),
			int(QuadPosA[2].x + 1280.0f - ScrollX), int(QuadPosA[2].y + ScrollY),
			int(QuadPosA[3].x + 1280.0f - ScrollX), int(QuadPosA[3].y + ScrollY),
			0, 0,
			0, 0,
			tex,
			WHITE
		);

		Novice::DrawQuad(
			int(QuadPosB[0].x + 1280.0f - ScrollX), int(QuadPosB[0].y + ScrollY),
			int(QuadPosB[1].x + 1280.0f - ScrollX), int(QuadPosB[1].y + ScrollY),
			int(QuadPosB[2].x + 1280.0f - ScrollX), int(QuadPosB[2].y + ScrollY),
			int(QuadPosB[3].x + 1280.0f - ScrollX), int(QuadPosB[3].y + ScrollY),
			0, 0,
			0, 0,
			tex,
			WHITE
		);


		Novice::DrawQuad(
			int(QuadPosA[0].x + 1280.0f - ScrollX), int(QuadPosA[0].y - 720.0f + ScrollY),
			int(QuadPosA[1].x + 1280.0f - ScrollX), int(QuadPosA[1].y - 720.0f + ScrollY),
			int(QuadPosA[2].x + 1280.0f - ScrollX), int(QuadPosA[2].y - 720.0f + ScrollY),
			int(QuadPosA[3].x + 1280.0f - ScrollX), int(QuadPosA[3].y - 720.0f + ScrollY),
			0, 0,
			0, 0,
			tex,
			WHITE
		);

		Novice::DrawQuad(
			int(QuadPosB[0].x + 1280.0f - ScrollX), int(QuadPosB[0].y - 720.0f + ScrollY),
			int(QuadPosB[1].x + 1280.0f - ScrollX), int(QuadPosB[1].y - 720.0f + ScrollY),
			int(QuadPosB[2].x + 1280.0f - ScrollX), int(QuadPosB[2].y - 720.0f + ScrollY),
			int(QuadPosB[3].x + 1280.0f - ScrollX), int(QuadPosB[3].y - 720.0f + ScrollY),
			0, 0,
			0, 0,
			tex,
			WHITE
		);


		Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0xFFFFFF00 + BlockColor, kFillModeSolid);
		
		if (scenefi == 3) {
			Novice::DrawBox(
				int(effect2.x - ScrollX), int(effect2.y),
				int(effectradius2.x), int(effectradius2.y),
				0.0f, BLACK, kFillModeSolid);
		}
		
		if (effectfige >= 1) {
			Novice::DrawEllipse(
				int(effect.x), int(effect.y),
				int(effectradius.x), int(effectradius.y),
				0.0f,
				WHITE,
				kFillModeSolid);
		}


			Novice::DrawQuad(
				int(TrianglePos1[0].x), int(TrianglePos1[0].y),
				int(TrianglePos1[1].x), int(TrianglePos1[1].y),
				int(TrianglePos1[2].x), int(TrianglePos1[2].y),
				int(TrianglePos1[3].x), int(TrianglePos1[3].y),
				0, 0,
				0, 0,
				tex,
				BLACK
			);

			Novice::DrawQuad(
				int(TrianglePos2[0].x), int(TrianglePos2[0].y),
				int(TrianglePos2[1].x), int(TrianglePos2[1].y),
				int(TrianglePos2[2].x), int(TrianglePos2[2].y),
				int(TrianglePos2[3].x), int(TrianglePos2[3].y),
				0, 0,
				0, 0,
				tex,
				BLACK
			);
			Novice::DrawQuad(
				int(TrianglePos3[0].x), int(TrianglePos3[0].y),
				int(TrianglePos3[1].x), int(TrianglePos3[1].y),
				int(TrianglePos3[2].x), int(TrianglePos3[2].y),
				int(TrianglePos3[3].x), int(TrianglePos3[3].y),
				0, 0,
				0, 0,
				tex,
				BLACK
			);
			Novice::DrawQuad(
				int(TrianglePos4[0].x), int(TrianglePos4[0].y),
				int(TrianglePos4[1].x), int(TrianglePos4[1].y),
				int(TrianglePos4[2].x), int(TrianglePos4[2].y),
				int(TrianglePos4[3].x), int(TrianglePos4[3].y),
				0, 0,
				0, 0,
				tex,
				BLACK
			);

	
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
