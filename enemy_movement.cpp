using System.Collections;
using System.Collections.Generic; using UnityEngine;

public class EnemyMovement : MonoBehaviour
{

Rigidbody2D myEnemyBody;
[SerializeField] float SpeedOfEnemy = 1f;
// Start is called before the first frame update void Start()
{
myEnemyBody = GetComponent<Rigidbody2D>();
}

// Update is called once per frame void Update()
{
myEnemyBody.velocity = new Vector2(SpeedOfEnemy,0f);
}

void OnTriggerExit2D(Collider2D other) { SpeedOfEnemy = -SpeedOfEnemy; FlipEnemy();
}
void FlipEnemy(){
transform.localScale = new Vector2(- (Mathf.Sign(myEnemyBody.velocity.x)), 1f);
}
}
