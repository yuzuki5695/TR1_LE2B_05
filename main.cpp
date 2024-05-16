#include <Novice.h>
#include <Vector2.h>
#define _USE_MATH_DEFINES
#include <math.h>

const char kWindowTitle[] = "LE2B_05_オノデラ_ユヅキ_タイトル";


float EaseOutExpo(float t) {
	return t == 1.0f
		? 1.0f
		: 1.0f - powf(2.0f, -10.0f * t);
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
	int movepos = 0;

	int Scene = 0;

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

		

		
		if (keys[DIK_SPACE] && Easeingflge == 0) {
			movepos = 1;		
			Easeingflge = 1;
			inte = 1;
		}

		if (movepos == 1) {
			Player.y += moveY;
			if (Player.y >= 345.0f) {
				Player.y = 345.0f;
				flag[0] = 1;
				movepos = 0;
			}
		}if (movepos == 2) {
			Player.y -= moveY;
			if (Player.y <= 315.0f) {
				Player.y = 315.0f;	
				inte = 0;
				movepos = 0;
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
					Scene++;
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
					movepos = 2;
				}


			}


			if (Scene >= 2) {
				Scene = 0;
			}


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		if (Scene == 1) {
			Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0xAAAAAAAA, kFillModeSolid);
		}


		if (Scene == 0) {
			Novice::DrawEllipse(
				int(Player.x), int(Player.y),
				int(radius.x), int(radius.y),
				0.0f,
				RED,
				kFillModeSolid
			);
		}else if (Scene == 1) {
			Novice::DrawEllipse(
				int(Player.x), int(Player.y),
				int(radius.x), int(radius.y),
				0.0f,
				BLUE,
				kFillModeSolid
			);
		}
	
		Novice::DrawQuad(
			int(QuadPosA[0].x), int(QuadPosA[0].y),
			int(QuadPosA[1].x), int(QuadPosA[1].y),
			int(QuadPosA[2].x), int(QuadPosA[2].y),
			int(QuadPosA[3].x), int(QuadPosA[3].y),
			0, 0,
			0, 0,
			tex,
			WHITE
		);

		Novice::DrawQuad(
			int(QuadPosB[0].x), int(QuadPosB[0].y),
			int(QuadPosB[1].x), int(QuadPosB[1].y),
			int(QuadPosB[2].x), int(QuadPosB[2].y),
			int(QuadPosB[3].x), int(QuadPosB[3].y),
			0, 0,
			0, 0,
			tex,
			WHITE
		);



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

		Novice::DrawLine(0,400,1280, 400,BLACK);


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
