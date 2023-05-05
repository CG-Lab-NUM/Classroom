#include "Nexus.h"

ANexus::ANexus()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ANexus::BeginPlay()
{
	Super::BeginPlay();
}

void ANexus::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANexus::addNexus(int numVertices, int sphereRadius, float scale, UStaticMesh* mesh) {
	if (numVertices <= 0 || sphereRadius <= 0) {
		UE_LOG(LogTemp, Warning, TEXT("Invalid Num Count or Sphere Radius"));
		return;
	}
	
	vertexMesh = NewObject<UInstancedStaticMeshComponent>(this);
	vertexMesh->RegisterComponent();
	vertexMesh->SetStaticMesh(mesh);
	vertexMesh->SetFlags(RF_Transactional);
	this->AddInstanceComponent(vertexMesh);

	float dTheta = 2.0f * PI / numVertices;
	float dPhi = PI / (numVertices - 1);
	for (int i = 0; i < numVertices; i++) {
		float theta = i * dTheta;
		for (int j = 0; j < numVertices; j++) {
			float phi = j * dPhi;
			FVector basePosition = GetActorLocation();
			FVector vertexPosition = FVector(
				sphereRadius * sin(phi) * cos(theta),
				sphereRadius * sin(phi) * sin(theta),
				sphereRadius * cos(phi)
			);
			FVector finalPosition = basePosition + vertexPosition;
			vertexMesh->AddInstance(FTransform(FRotator(), vertexPosition, FVector(scale)));
		}
	}
}


bool ANexus::shiftToLine(int sphereRadius, float scale, float elapsedTime, float duration) {
	const int numVertices = vertexMesh->GetInstanceCount();
	const float dTheta = 2 * PI / numVertices;
	float t = FMath::Clamp(elapsedTime / duration, 0.0f, 1.0f);

	for (int i = 0; i < numVertices; i++) {
		FTransform transform;
		vertexMesh->GetInstanceTransform(i, transform);
		FVector startPoint = transform.GetLocation();
		FVector endPoint = FVector(
			0,
			i * 10,
			0
		);
		FVector finalPosition = FMath::VInterpTo(startPoint, endPoint, t, 0.5);

		vertexMesh->UpdateInstanceTransform(i, FTransform(FRotator(), finalPosition, FVector(scale)), false, true, true);
	}
	if (t >= 1) {
		return true;
	}
	return false;

}

bool ANexus::shiftToSphere1(int sphereRadius, float scale, float elapsedTime, float duration) {
	const int numVertices = vertexMesh->GetInstanceCount();
	//const float dTheta = 2 * PI / numVertices;
	float t = FMath::Clamp(elapsedTime / duration, 0.0f, 1.0f);
	float dTheta = 2.0f * PI / numVertices / 10;
	float dPhi = PI / (numVertices - 1);
	int count = 0;

	for (int i = 0; i < numVertices / 10; i++) {
		float theta = i * dTheta;
		for (int j = 0; j < numVertices / 10; j++) {
			count++;
			float phi = j * dPhi;
			FVector basePosition = GetActorLocation();
			FVector vertexPosition = FVector(
				sphereRadius * sin(phi) * cos(theta),
				sphereRadius * sin(phi) * sin(theta),
				sphereRadius * cos(phi)
			);
			FTransform transform;
			vertexMesh->GetInstanceTransform(i, transform);
			FVector startPoint = transform.GetLocation();
			FVector finalPosition = FMath::VInterpTo(startPoint, vertexPosition, t, 0.5);
			vertexMesh->UpdateInstanceTransform(count, FTransform(FRotator(), finalPosition, FVector(scale)), false, true, true);
		}
	}
	if (t >= 1) {
		return true;
	}
	return false;

}

