
// hplotView.cpp : implementation of the ChplotView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "hplot.h"
#endif

#include "hplotDoc.h"
#include "hplotView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ChplotView

IMPLEMENT_DYNCREATE(ChplotView, CView)

BEGIN_MESSAGE_MAP(ChplotView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &ChplotView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// ChplotView construction/destruction

ChplotView::ChplotView() noexcept
{
	// TODO: add construction code here

}

ChplotView::~ChplotView()
{
}

BOOL ChplotView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// ChplotView drawing

void ChplotView::OnDraw(CDC* /*pDC*/)
{
	ChplotDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// ChplotView printing


void ChplotView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL ChplotView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void ChplotView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void ChplotView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void ChplotView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void ChplotView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// ChplotView diagnostics

#ifdef _DEBUG
void ChplotView::AssertValid() const
{
	CView::AssertValid();
}

void ChplotView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

ChplotDoc* ChplotView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(ChplotDoc)));
	return (ChplotDoc*)m_pDocument;
}
#endif //_DEBUG


// ChplotView message handlers
