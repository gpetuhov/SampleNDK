package com.gpetuhov.android.samplendk

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import com.pawegio.kandroid.toast
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Example of a call to a native method
        sample_text.text = "${addFromJNI(10, 5)}"

        sample_text.setOnClickListener {
            // "Calculations" are performed inside the native code.
            // Result is returned via callback (Kotlin method is called from native code)
            calculate()
        }
    }

    // This method is called from inside the native code
    fun onCalculationsComplete(result: Int) {
        toast("Calculations result = $result")
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    // This method name must be the same as the last segment of the native method name
    external fun addFromJNI(x: Int, y: Int): Int

    external fun calculate()

    companion object {

        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }
}
