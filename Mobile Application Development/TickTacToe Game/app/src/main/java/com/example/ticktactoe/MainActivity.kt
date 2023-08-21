package com.example.ticktactoe

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.ImageView
import android.widget.TextView

class MainActivity : AppCompatActivity() {
    private var gameActive = true
    private var activePlayer = 0
    private val gameState = intArrayOf(2, 2, 2, 2, 2, 2, 2, 2, 2)
    private val winPositions = arrayOf(
        intArrayOf(0, 1, 2),
        intArrayOf(3, 4, 5),
        intArrayOf(6, 7, 8),
        intArrayOf(0, 3, 6),
        intArrayOf(1, 4, 7),
        intArrayOf(2, 5, 8),
        intArrayOf(0, 4, 8),
        intArrayOf(2, 4, 6)
    )

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
    }

    fun playerTap(view: View) {
        val img = view as ImageView
        val tappedImage = img.tag.toString().toInt()
        if (!gameActive) {
            gameReset(view)
        }
        if (gameState[tappedImage] == 2) {
            gameState[tappedImage] = activePlayer
            img.translationY = -1000f
            if (activePlayer == 0) {
                img.setImageResource(R.drawable.x)
                activePlayer = 1
                val status = findViewById<TextView>(R.id.status)
                status.text = "O's Turn - Tap to play"
            } else {
                img.setImageResource(R.drawable.o)
                activePlayer = 0
                val status = findViewById<TextView>(R.id.status)
                status.text = "X's Turn - Tap to play"
            }
            img.animate().translationYBy(1000f).duration = 300
        }
        for (winPosition in winPositions) {
            if (gameState[winPosition[0]] == gameState[winPosition[1]] &&
                gameState[winPosition[1]] == gameState[winPosition[2]] &&
                gameState[winPosition[0]] != 2
            ) {
                gameActive = false
                val winnerStr: String = if (gameState[winPosition[0]] == 0) {
                    "X has won"
                } else {
                    "O has won"
                }
                val status = findViewById<TextView>(R.id.status)
                status.text = winnerStr
            }
        }
    }

    private fun gameReset(view: View) {
        gameActive = true
        activePlayer = 0
        for (i in gameState.indices) {
            gameState[i] = 2
        }
        findViewById<ImageView>(R.id.imageView0).setImageResource(0)
        findViewById<ImageView>(R.id.imageView1).setImageResource(0)
        findViewById<ImageView>(R.id.imageView2).setImageResource(0)
        findViewById<ImageView>(R.id.imageView3).setImageResource(0)
        findViewById<ImageView>(R.id.imageView4).setImageResource(0)
        findViewById<ImageView>(R.id.imageView5).setImageResource(0)
        findViewById<ImageView>(R.id.imageView6).setImageResource(0)
        findViewById<ImageView>(R.id.imageView7).setImageResource(0)
        findViewById<ImageView>(R.id.imageView8).setImageResource(0)
        val status = findViewById<TextView>(R.id.status)
        status.text = "X's Turn - Tap to play"
    }
}