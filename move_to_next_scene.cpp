using System.Collections;
using System.Collections.Generic; using UnityEngine;
using UnityEngine.SceneManagement; public class Exit : MonoBehaviour
{
void OnTriggerEnter2D(Collider2D other) {
int CurrentSceneIndex = SceneManager.GetActiveScene().buildIndex; SceneManager.LoadScene(CurrentSceneIndex + 1);
}
}
