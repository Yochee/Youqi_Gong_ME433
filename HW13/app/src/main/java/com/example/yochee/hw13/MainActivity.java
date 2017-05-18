package com.example.yochee.hw13;
// libraries

import android.Manifest;
import android.app.Activity;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.SurfaceTexture;
import android.hardware.Camera;
import android.os.Bundle;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.TextureView;
import android.view.WindowManager;
import android.widget.TextView;
import android.widget.SeekBar;
import android.widget.SeekBar.OnSeekBarChangeListener;

import java.io.IOException;

import static android.graphics.Color.blue;
import static android.graphics.Color.green;
import static android.graphics.Color.red;
import static android.graphics.Color.rgb;

public class MainActivity extends Activity implements TextureView.SurfaceTextureListener {
    private Camera mCamera;
    private TextureView mTextureView;
    private SurfaceView mSurfaceView;
    private SurfaceHolder mSurfaceHolder;
    private Bitmap bmp = Bitmap.createBitmap(640, 480, Bitmap.Config.ARGB_8888);
    private Canvas canvas = new Canvas(bmp);
    private Paint paint1 = new Paint();
    private TextView mTextView;
    private SeekBar myControl;
    int sensitivity;
    private void setMyControlListener() {
        myControl.setOnSeekBarChangeListener(new OnSeekBarChangeListener() {
            int progressChanged = 0;
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                progressChanged = progress;
                sensitivity = progress;
            }
            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {
            }
            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
            }
        });
    }
    static long prevtime = 0; // for FPS calculation

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON); // keeps the screen from turning off

        mTextView = (TextView) findViewById(R.id.cameraStatus);

        // see if the app has permission to use the camera
        ActivityCompat.requestPermissions(MainActivity.this, new String[]{Manifest.permission.CAMERA}, 1);
        if (ContextCompat.checkSelfPermission(this, Manifest.permission.CAMERA) == PackageManager.PERMISSION_GRANTED) {
            mSurfaceView = (SurfaceView) findViewById(R.id.surfaceview);
            mSurfaceHolder = mSurfaceView.getHolder();

            mTextureView = (TextureView) findViewById(R.id.textureview);
            mTextureView.setSurfaceTextureListener(this);

            mTextView = (TextView) findViewById(R.id.cameraStatus);
            myControl = (SeekBar) findViewById(R.id.seek1);

            // set the paintbrush for writing text on the image
            paint1.setColor(0xffff0000); // red
            paint1.setTextSize(24);
            setMyControlListener();

            mTextView.setText("started camera");
        } else {
            mTextView.setText("no camera permissions");
        }

    }

    public void onSurfaceTextureAvailable(SurfaceTexture surface, int width, int height) {
        mCamera = Camera.open();
        Camera.Parameters parameters = mCamera.getParameters();
        parameters.setPreviewSize(640, 480);
        parameters.setFocusMode(Camera.Parameters.FOCUS_MODE_INFINITY); // no autofocusing
        parameters.setAutoExposureLock(true); // keep the white balance constant
        mCamera.setParameters(parameters);
        mCamera.setDisplayOrientation(90); // rotate to portrait mode

        try {
            mCamera.setPreviewTexture(surface);
            mCamera.startPreview();
        } catch (IOException ioe) {
            // Something bad happened
        }
    }

    public void onSurfaceTextureSizeChanged(SurfaceTexture surface, int width, int height) {
        // Ignored, Camera does all the work for us
    }

    public boolean onSurfaceTextureDestroyed(SurfaceTexture surface) {
        mCamera.stopPreview();
        mCamera.release();
        return true;
    }

    // the important function
    public void onSurfaceTextureUpdated(SurfaceTexture surface) {
        // every time there is a new Camera preview frame
        mTextureView.getBitmap(bmp);
        final Canvas c = mSurfaceHolder.lockCanvas();
        if (c != null) {
            int thresh = sensitivity; // comparison value
            int widthgap = 3;
            int height = bmp.getHeight()/widthgap;
            int[][] pixels = new int[height][bmp.getWidth()]; // pixels[] is the RGBA data
            for (int j = 0; j<height; j++) {    // j is the index of the row of array
                int y = j*widthgap;                // every 5 pixel each row
                bmp.getPixels(pixels[j], 0, bmp.getWidth(), 0, y, bmp.getWidth(), 1);
                for (int i = 0; i < bmp.getWidth(); i++) {
                    if ((green(pixels[j][i])*3-(green(pixels[j][i])+red(pixels[j][i])+blue(pixels[j][i]))) > thresh) {
                        pixels[j][i] = rgb(0, 255, 0); // over write the pixel with pure green
                    }
                }
                bmp.setPixels(pixels[j], 0, bmp.getWidth(), 0, y, bmp.getWidth(), 1);
            }
        }
        // draw a circle at some position
        int pos = 50;
        canvas.drawCircle(pos, 240, 5, paint1); // x position, y position, diameter, color
        // write the pos as text
        canvas.drawText("Thresh = " + sensitivity, 10, 200, paint1);
        c.drawBitmap(bmp, 0, 0, null);
        mSurfaceHolder.unlockCanvasAndPost(c);
        // calculate the FPS to see how fast the code is running
        long nowtime = System.currentTimeMillis();
        long diff = nowtime - prevtime;
        mTextView.setText("FPS " + 1000 / diff);
        prevtime = nowtime;
    }
}