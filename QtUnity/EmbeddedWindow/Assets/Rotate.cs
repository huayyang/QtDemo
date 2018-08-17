using UnityEngine;
using System.Collections;
using System;
using System.Runtime.InteropServices;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Net.Sockets;


public class Rotate : MonoBehaviour {
    private TcpClient socketConnection;
    private Thread clientReceiveThread;

    byte[] data;
    string Error_Message;
    const int portNo = 8888;

    private string serverMessage;
    private bool stopRotate = false;

    // Use this for initialization
    void Start () {
        clientReceiveThread = new Thread(new ThreadStart(ListenForData));
        clientReceiveThread.IsBackground = true;
        //clientReceiveThread.Start();

        data = new byte[1024];

        serverMessage = "No Message";
    }

    private void ListenForData() {
        try {
            socketConnection = new TcpClient("127.0.0.1", portNo);
            Byte[] bytes = new Byte[1024];
            serverMessage = "Thread Start";
            while (true) {
                // Get a stream object for reading 				
                using (NetworkStream stream = socketConnection.GetStream()) {
                    int length;
                    // Read incomming stream into byte arrary. 					
                    while ((length = stream.Read(bytes, 0, bytes.Length)) != 0) {
                        var incommingData = new byte[length];
                        Array.Copy(bytes, 0, incommingData, 0, length);
                        // Convert byte array to string message. 						
                        serverMessage = Encoding.ASCII.GetString(incommingData);
                        Debug.Log("server message received as: " + serverMessage);
                        stopRotate = !stopRotate;
                    }
                }
            }
        } catch (SocketException socketException) {
            Debug.Log("Socket exception: " + socketException);
            serverMessage = "Socket exception: " + socketException;
        }
    }

    // Update is called once per frame
    void Update () {
        if (!clientReceiveThread.IsAlive) {
            clientReceiveThread.Start();
        }
        if (stopRotate) {
            transform.Rotate(Vector3.up, Time.deltaTime * 80.0f);
        }
    }

	void OnGUI()
	{
        GUILayout.Label(serverMessage);
    }
}
